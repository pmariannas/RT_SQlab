#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>


int main()
{   
    
        int nbytes;
        int status;

        int fd[2];
        char string[] = "i am child \n";
        char readbuffer[80];

        char string2[] = "Hello son \n";
        char readbuffer2[80];
        pid_t pid;
        
        printf("\n----> [%i] Hi I am the parent\n", getpid());
        
        pipe(fd);
        pid = fork();
        if(pid > 0)
        {
                /* Parent process closes up output side of pipe */
                close(fd[0]);
                write(fd[1], string2, (strlen(string2)+1));
                waitpid(pid, &status, 0);
                printf("---> %s\n", string2);
                /* Read in a string from the pipe */
                nbytes = read(fd[0], readbuffer2, sizeof(readbuffer2));


        }
        else
        {
                /* Child process closes up input side of pipe */
                close(fd[1]);
                nbytes = read(fd[0], readbuffer, sizeof(readbuffer));

                /* Send "string" through the output side of pipe */
                write(fd[1], string, (strlen(string)+1));
                printf("---> %s\n", string);


        }

        
    return 0;

    
}