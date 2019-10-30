#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp)
{
   int fds[2];
   int returnstatus = pipe(fds);

   if (returnstatus == -1)
   {
      printf("Unable to create pipe\n");
      return 1;
   }

   if (!fork())
   {
      close(1);
      dup2(fds[1], 1); // write to pipe -
      close(fds[0]);
      return execlp("/bin/ls", "/bin/ls", "-l", NULL);
   }

   if (!fork())
   {
      close(0);
      dup2(fds[0], 0); // read to pipe -
      close(fds[1]);
      return execlp("/usr/bin/wc", "/bin/wc", "-l", NULL);
   }
   //close the parent connection to the pipe
   close(fds[0]);
   close(fds[1]);
   //this is the parent
   wait(NULL);
   wait(NULL);
   return EXIT_SUCCESS;
}