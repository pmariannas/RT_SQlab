#include <linux/module.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/cdev.h>
#include <linux/printk.h> /*for pr_err*/
#include <linux/list.h>
#include <linux/uaccess.h>
#include <linux/wait.h>
#include <linux/spinlock.h>
#include <linux/sched.h>

#include "myQueueM.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Marianna");
MODULE_DESCRIPTION("implementation for IPC");

static int QUEUE_COUNT = 8;
const size_t MESSAGE_SIZE = 4096;
/*static int first_minor;*/
/* this is the first dev_t allocated to us... */
static dev_t first_dev;
/* this variable will store the class */
static struct class *my_class;
/* this variable will hold our cdev struct */
static struct cdev my_cdev;

/* struct for mess queue */
struct mq_t
{
	struct list_head head;
	struct device *mq_dev;
	size_t numOfMess; //count of mgs in list
	size_t size;

	wait_queue_head_t mq_wait; /*p. 309*/
	struct mutex lockMutex;
};

/* struct for node */
struct node_t
{
	struct list_head headNode;
	size_t sizeOfData;
	char *dataMess;
};

/* automatically initialised to NULL... */
static struct mq_t *mq;

/*  constructur */
static inline void queue_ctor(struct mq_t *mq)
{
	mq->numOfMess = 0;
	INIT_LIST_HEAD(&(mq->head));
	init_waitqueue_head(&mq->mq_wait);
	mutex_init(&mq->lockMutex);
}

/*  destructor */
static inline void queue_dtor(struct mq_t *mq)
{
	struct node_t *node;
	list_for_each_entry(node, &mq->head, headNode)
	{
		kfree(node->dataMess);
		kfree(node);
	}

	mutex_destroy(&mq->lockMutex);
}

/*queue_open*/
static int queue_open(struct inode *inode, struct file *pfile)
{
	int queue_num = iminor(inode) - MINOR(first_dev);
	pfile->private_data = mq + queue_num;
	return 0;
}

static int my_list_mutex_not_empty(struct mq_t *mq)
{
	int ret;
	ret = mutex_lock_interruptible(&mq->lockMutex);
	if (ret != 0)
	{
		pr_err("%s: error in lock mutex\n", THIS_MODULE->name);
		return ret;
	}
	ret = list_empty(&mq->head); /*return 0 if list not empty, return true if list empty*/
	if (ret != 0)				 /*if list empty*/
	{
		mutex_unlock(&mq->lockMutex); /*release the mutex */
	}
	return ret;
}

static long mq_ioctl(struct file *pfile, unsigned int option, unsigned long usr_buff)
{
	struct mq_t *mq = pfile->private_data;
	int err;
	int ret;
	int res = 0;
	char *my_buff;
	struct mq_reg r;
	struct mq_reg *argp = (struct mq_reg *)usr_buff;
	struct node_t *new_node;

	switch (option)
	{
	case MQ_RECV_MSG: /*get*/
	{
		/*old
		ret = wait_event_interruptible(mq->mq_wait, list_empty(&mq->head) == 0);
		*/
		ret = wait_event_interruptible(mq->mq_wait, my_list_mutex_not_empty(mq) == 0);

		if (ret)
		{
			pr_err("%s: error in wait\n", THIS_MODULE->name);
			return ret;
		}
		/*
		ret = mutex_lock_interruptible(&mq->lockMutex);
		if (ret)
		{
			pr_err("%s: error in lock mutex\n", THIS_MODULE->name);
			return ret;
		}
*/

		new_node = list_entry((&mq->head)->prev, struct node_t, headNode);

		ret = copy_to_user((char *)usr_buff, new_node->dataMess, new_node->sizeOfData);
		if (ret)
		{
			pr_err("%s: error in copy to user\n", THIS_MODULE->name);
			return ret;
		}

		list_del((&mq->head)->prev);
		res = new_node->sizeOfData;
		mutex_unlock(&mq->lockMutex); /*release the mutex */

		kfree(new_node->dataMess);
		kfree(new_node);
		mq->numOfMess--;
		wake_up_interruptible(&mq->mq_wait);
		return res;

		break;
	}

	case MQ_SEND_MSG: /*set*/
	{
		err = copy_from_user(&r, argp, sizeof(r));
		if (err)
		{
			pr_err("%s: error in copy from user\n", THIS_MODULE->name);
			return err;
		}
		pr_err("the pointer from user %p  \n", &r);
		my_buff = (char *)kmalloc(r.size, GFP_KERNEL);
		if (IS_ERR(my_buff))
		{
			pr_err("%s: error in kmalloc\n", THIS_MODULE->name);
			err = PTR_ERR(my_buff);
			return err;
		}

		err = copy_from_user(my_buff, r.data, r.size);
		if (err < 0)
		{
			pr_err("%s: error in copy from user\n", THIS_MODULE->name);
			return err;
		}

		new_node = kmalloc(sizeof(new_node), GFP_KERNEL);
		if (IS_ERR(new_node))
		{
			pr_err("%s: error in kmalloc\n", THIS_MODULE->name);
			err = PTR_ERR(new_node);
			return err;
		}
		new_node->dataMess = my_buff;
		new_node->sizeOfData = r.size;
		ret = mutex_lock_interruptible(&mq->lockMutex);
		if (ret)
		{
			pr_err("%s: error in lock mutex\n", THIS_MODULE->name);
			return ret;
		}

		list_add_tail((&new_node->headNode), &(mq->head));
		mq->numOfMess++;
		mutex_unlock(&mq->lockMutex); /*release the mutex */

		wake_up_interruptible(&mq->mq_wait);
		return r.size;
		/*init_waitqueue_head(&my_mq->mq_busy_wait); */ /*p. 310 */
		break;
	}
	}
	return res;
}

/*
static int queue_release(struct inode *inode, struct file *pfile)
{
	pr_info("we are here in release function!!!\n");
	return 0;
}
*/

/*  struct file_operations */
static const struct file_operations mq_fops = {
	.owner = THIS_MODULE,
	.open = queue_open,
	.unlocked_ioctl = mq_ioctl,
	/*.release = queue_release,*/
};

static int __init queue_init(void)
{
	int err = 0;
	int i;
	/* allocate queue */
	mq = kmalloc(sizeof(struct mq_t) * QUEUE_COUNT, GFP_KERNEL);
	if (IS_ERR(mq))
	{
		pr_err("kmalloc\n");
		err = PTR_ERR(mq);
		goto err_return;
	}
	/* initialize queue */
	for (i = 0; i < QUEUE_COUNT; i++)
	{
		queue_ctor(mq + i);
	}

	/* allocate our own range of devices */
	err = alloc_chrdev_region(&first_dev, 0, QUEUE_COUNT, THIS_MODULE->name);
	if (err)
	{
		pr_err("cannot alloc_chrdev_region\n");
		goto err_final;
	}
	pr_info("allocated the region\n");

	/* add the cdev structure, no error codes */
	cdev_init(&my_cdev, &mq_fops);

	/*add a char device to the system */
	err = cdev_add(&my_cdev, first_dev, QUEUE_COUNT);
	if (err)
	{
		pr_err("cannot cdev_add\n");
		goto err_dealloc;
	}

	pr_info("added the cdev\n");

	/*create a struct class structure */
	my_class = class_create(THIS_MODULE, THIS_MODULE->name);
	if (IS_ERR(my_class))
	{
		pr_err("failed in class_create\n");
		err = PTR_ERR(my_class);
		goto err_dealloc;
	}

	pr_info("created the class\n");

	/* creates a device for queue */
	for (i = 0; i < QUEUE_COUNT; i++)
	{
		/* and now lets auto-create a /dev/ node */
		mq[i].mq_dev = device_create(my_class, NULL,
									 MKDEV(MAJOR(first_dev), MINOR(first_dev) + i),
									 NULL, "%s%d", THIS_MODULE->name, i);
		if (IS_ERR(mq[i].mq_dev))
		{
			pr_err("device_create\n");
			err = PTR_ERR(mq[i].mq_dev);
			goto err_class;
		}
	}

	pr_info(KBUILD_MODNAME " loaded successfully\n");

	pr_info("created the device\n");

	pr_info("loaded ok\n");

	return 0;

err_class:
	class_destroy(my_class); /*destroys a struct class structure*/
/*err_cdev_del:
	cdev_del(&my_cdev);*/
err_dealloc:
	unregister_chrdev_region(first_dev, QUEUE_COUNT);
err_final:
	for (i = 0; i < QUEUE_COUNT; i++)
		queue_dtor(mq + i);
	kfree(mq);
err_return:
	return err;
}

static void __exit queue_exit(void)
{
	int i;
	for (i = 0; i < QUEUE_COUNT; i++)
	{
		device_destroy(my_class, MKDEV(MAJOR(first_dev), MINOR(first_dev) + i));
	}
	class_destroy(my_class);
	cdev_del(&my_cdev);
	unregister_chrdev_region(first_dev, QUEUE_COUNT);
	for (i = 0; i < QUEUE_COUNT; i++)
	{
		queue_dtor(mq + i);
	}

	kfree(mq);
	pr_info(KBUILD_MODNAME " unloaded successfully\n");
}

module_init(queue_init);
module_exit(queue_exit);
