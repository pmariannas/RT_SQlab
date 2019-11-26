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

int main(int argc, char** argv, char**envp)
{
	int fd, ret;
	char* s="/dev/myQueue0";
	fd=open(s,O_RDWR);  
	if(fd==-1) {
		fprintf(stderr, "open error\n"); 
		return 1;
	}

	struct  mq_reg m;
	char* str;
	if(argc>1) {
		str=argv[1];
	} else {
		str="hello";
	}
	m.data=str;
	m.size=strlen(str);
	ret=ioctl(fd,MQ_SEND_MSG,&m);
	if(ret==-1) {
		fprintf(stderr, "ioctl error\n"); 
		return 1;
	}
	printf("the return value of ioctl is %d\n", ret);

	ret=close(fd);
	if(ret==-1) {
		fprintf(stderr, "close error\n"); 
		return 1;
	}

	return 0;
}
