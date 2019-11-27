#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <linux/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "myQueueM.h"

void *putsF(void *arg)
{

    int fd, ret;
    char *s = "/dev/myQueue1";
    fd = open(s, O_RDWR);
    if (fd == -1)
    {
        fprintf(stderr, "open error\n");
        return (void *)1;
    }

    struct mq_reg m;
    char *str;

    str = "hello";

    m.data = str;
    m.size = strlen(str);
    ret = ioctl(fd, MQ_SEND_MSG, &m);
    if (ret == -1)
    {
        fprintf(stderr, "ioctl error\n");
        return (void *)1;
    }
    printf("the return value of ioctl is %d\n", ret);

    ret = close(fd);
    if (ret == -1)
    {
        fprintf(stderr, "close error\n");
        return (void *)1;
    }
}

void *getsF()
{

    int fd, ret;
    char *s = "/dev/myQueue1";
    fd = open(s, O_RDWR);
    if (fd == -1)
    {
        fprintf(stderr, "open error\n");
        return (void *)1;
    }

    char *str = (char *)malloc(4096);

    ret = ioctl(fd, MQ_RECV_MSG, str);

    if (ret == -1)
    {
        fprintf(stderr, "ioctl error\n");
        return (void *)1;
    }
    printf("ret value : %d\n", ret);
    //printf("the message is %s\n", str);

    ret = close(fd);
    if (ret == -1)
    {
        fprintf(stderr, "close error\n");
        return (void *)1;
    }
}

int main(int argc, char **argv, char **envp)
{

    pthread_t puts[100];
    pthread_t gets[100];

    int i, j, w, z;

    for (i = 0; i < 100; i++)
    {
        pthread_create(&puts[i], NULL, putsF, &i);
        pthread_create(&gets[i], NULL, getsF, &j);
    }
    /*
    for (j = 0; j < 50; j++)
    {
        pthread_create(&gets[j], NULL, getsF, &j);
    }
*/
    for (w = 0; w < 100; w++)
    {
        pthread_join(puts[w], NULL);
    }

    for (z = 0; z < 100; z++)
    {
        pthread_join(gets[z], NULL);
    }
    return 0;
}