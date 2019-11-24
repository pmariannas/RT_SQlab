#include <linux/module.h> 
#include <linux/fs.h>
#include <linux/device.h> 
#include <linux/slab.h>
#include <linux/cdev.h> 
#include <linux/printk.h> /*for pr_err*/
#include <linux/list.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Marianna");
MODULE_DESCRIPTION("implementation for IPC");


static int queue_count = 8;
/*static int first_minor;*/
/* this is the first dev_t allocated to us... */
static dev_t first_dev;
/* this variable will store the class */
static struct class* my_class;
/* this variable will hold our cdev struct */
static struct cdev my_cdev;
static LIST_HEAD(message_list);


/* struct for queue */
struct queue_t {
	struct device* mq_dev;
	struct list_head node;
	size_t size;//count of mgs in list 
	/*
	size_t capacity;
	size_t front;
	size_t rear; 
	int* array; 
	*/
	
};

/* automatically initialised to NULL... */
static struct queue_t *buffer;

/* pipe constructur */
static inline void queue_ctor(struct queue_t *queue)
{
	/*TO DO*/
}

/* queue destructor */
static inline void queue_dtor(const struct queue_t *queue)
{
	/*kfree(queue->mq_dev);*/
}


static int queue_open(struct inode *inode, struct file *file)
{	
	pr_info("we are here in open function!!!\n");
	return 0;
}


/*
static int queue_release(struct inode *inode, struct file *file)
{
	pr_info("we are here in release function!!!\n");
	return 0;
}
*/

static const struct file_operations queue_fops = {
	.owner = THIS_MODULE,
	.open = queue_open,
	/*.ioctl = queue_ioctl,
	.release = queue_release,*/
};


static int __init queue_init(void)
{
	int err = 0;
	int i;
	/* allocate queue */
	buffer = kmalloc(sizeof(struct queue_t)*queue_count, GFP_KERNEL);
	if (IS_ERR(buffer)) {
		pr_err("kmalloc\n");
		err = PTR_ERR(buffer);
		goto err_return;
	}
	/* initialize queue */
	for (i = 0; i < queue_count; i++)
	{
		queue_ctor(buffer+i);
	}
		

	/* allocate our own range of devices */
	err = alloc_chrdev_region(&first_dev, 0, queue_count, THIS_MODULE->name);
	if (err) {
		pr_err("cannot alloc_chrdev_region\n");
		goto err_final;
	}
	pr_info("allocated the region\n");
	
	/* add the cdev structure, no error codes */
	cdev_init(&my_cdev, &queue_fops);
	
	/*add a char device to the system */
	err = cdev_add(&my_cdev, first_dev, queue_count);
	if (err) {
		pr_err("cannot cdev_add\n");
		goto err_dealloc;
	}

	pr_info("added the cdev\n");

	/*create a struct class structure */
	my_class = class_create(THIS_MODULE, THIS_MODULE->name);
	if (IS_ERR(my_class)) {
		pr_err("failed in class_create\n");
		err = PTR_ERR(my_class);
		goto err_dealloc;
	}

	pr_info("created the class\n");

	/* creates a device for queue */
	for (i = 0; i < queue_count; i++) 
	{
		/* and now lets auto-create a /dev/ node */
		buffer[i].mq_dev = device_create(my_class, NULL,
			MKDEV(MAJOR(first_dev), MINOR(first_dev)+i),
			NULL, "%s%d", THIS_MODULE->name, i);
		if (IS_ERR(buffer[i].mq_dev)) 
		{
			pr_err("device_create\n");
			err = PTR_ERR(buffer[i].mq_dev);
			goto err_class;
		}
	}
	
	pr_info(KBUILD_MODNAME " loaded successfully\n");

	pr_info("created the device\n");
	
	pr_info("loaded ok\n");

	return 0;


err_class:
	class_destroy(my_class); /*destroys a struct class structure*/
err_dealloc:
	unregister_chrdev_region(first_dev, queue_count);
err_final:
	for (i = 0; i < queue_count; i++)
		queue_dtor(buffer+i);
	kfree(buffer);
err_return:
	return err;	
}

static void __exit queue_exit(void)
{
	int i;
	for (i = 0; i < queue_count; i++)
	{
		device_destroy(my_class, MKDEV(MAJOR(first_dev),MINOR(first_dev)+i));
	}
	class_destroy(my_class);
	cdev_del(&my_cdev);
	unregister_chrdev_region(first_dev, queue_count);
	for (i = 0; i < queue_count; i++)
	{
		queue_dtor(buffer+i);
	}

	kfree(buffer);
	pr_info(KBUILD_MODNAME " unloaded successfully\n");
}

module_init(queue_init);
module_exit(queue_exit);
