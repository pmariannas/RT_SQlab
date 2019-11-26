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
#include "myQueueM.h"

int main()
{
	int fd, ret;
	char* s="/dev/myQueue0";
	fd=open(s,O_RDWR);  
	if(fd==-1) {
		fprintf(stderr, "open error\n"); 
		return 1;
	}

	char* str=(char*)malloc(4096);
	
	ret=ioctl(fd,MQ_RECV_MSG, str);
	
	if(ret==-1) {
		fprintf(stderr, "ioctl error\n"); 
		return 1;
	}
	printf("ret value : %d\n", ret);
	printf("the message is %s\n",str);

	ret=close(fd);
	if(ret==-1) {
		fprintf(stderr, "close error\n"); 
		return 1;
	}

	return 0;
}
