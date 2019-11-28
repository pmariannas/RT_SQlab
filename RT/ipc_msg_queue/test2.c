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
/**************************************/
/****TEST ONE DEVICE WITH WHILE(1)****/
/************************************/

void *putsF(void *arg)
{

    while (1)
    {

        int fd, ret;
        char *s = "/dev/myQueue0";
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
}

void *getsF()
{

    while (1)
    {

        int fd, ret;
        char *s = "/dev/myQueue0";
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

        ret = close(fd);
        if (ret == -1)
        {
            fprintf(stderr, "close error\n");
            return (void *)1;
        }
    }
}

int main(int argc, char **argv, char **envp)
{

    pthread_t puts[3];
    pthread_t gets[3];

    int i, w;

    for (i = 0; i < 3; i++)
    {
        pthread_create(&puts[i], NULL, putsF, &i);
        pthread_create(&gets[i], NULL, getsF, &i);
    }

    for (w = 0; w < 3; w++)
    {
        pthread_join(puts[w], NULL);
        pthread_join(gets[w], NULL);
    }

    return 0;
}