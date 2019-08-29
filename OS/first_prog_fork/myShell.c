#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <stdlib.h> 
#include <stdio.h>
int main()
{   
    
    int status;
    char *args[]={"./aprog",NULL}; 
    pid_t pid;
    printf("----> [%i] Hi I am the parent and I am about to create a child...\n", getpid());
    pid = fork();s   
    if(pid > 0) /*the father*/
    {
        waitpid(pid, &status, 0);

        printf("-----> end child process\n");
    }
    else
    {
        printf("----->  child process\n");
        fflush(stdout);
        execv(args[0],args);
    }
    
    return 0;

    
}