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

char *device;

void *putsF(void *arg)
{

    int fd, ret;
    fd = open(device, O_RDWR);
    if (fd == -1)
    {
        fprintf(stderr, "open error\n");
        return NULL;
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
        return NULL;
    }
    printf("the return value of ioctl is %d\n", ret);

    ret = close(fd);
    if (ret == -1)
    {
        fprintf(stderr, "close error\n");
        return NULL;
    }
}

void *getsF()
{

    int fd, ret;
    fd = open(device, O_RDWR);
    if (fd == -1)
    {
        fprintf(stderr, "open error\n");
        return NULL;
    }

    char *str = (char *)malloc(4096);

    ret = ioctl(fd, MQ_RECV_MSG, str);

    if (ret == -1)
    {
        fprintf(stderr, "ioctl error\n");
        return NULL;
    }
    printf("ret value : %d\n", ret);

    ret = close(fd);
    if (ret == -1)
    {
        fprintf(stderr, "close error\n");
        return NULL;
    }
}

int main(int argc, char **argv, char **envp)
{

    pthread_t puts[100];
    pthread_t gets[100];

    int i, w;

    if (argc == 2)
    {
        device = argv[1];
    }
    else
    {
        return 0;
    }

    for (i = 0; i < 100; i++)
    {
        pthread_create(&puts[i], NULL, putsF, &i);
        pthread_create(&gets[i], NULL, getsF, &i);
    }

    for (w = 0; w < 100; w++)
    {
        pthread_join(puts[w], NULL);
        pthread_join(gets[w], NULL);
    }

    
    return 0;
}