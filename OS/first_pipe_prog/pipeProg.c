#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>


int main()
{   
    
    int nbytes;
    int fd[2];
    char string[] = "i am child \n";
    char readbuffer[80];
    pid_t pid;
    
    printf("\n----> [%i] Hi I am the parent\n", getpid());
    
    pipe(fd);
    pid = fork();
    if(pid > 0)
    {
            /* Parent process closes up output side of pipe */
            close(fd[1]);

            /* Read in a string from the pipe */
            nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
                    fflush(stdout);
            printf("Received string: %s", readbuffer);
                    fflush(stdout);
    }
    else
    {
            /* Child process closes up input side of pipe */
            close(fd[0]);

            /* Send "string" through the output side of pipe */
            write(fd[1], string, (strlen(string)+1));
            exit(0);
    }

    
    return 0;

    
}