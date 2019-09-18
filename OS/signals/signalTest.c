#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int s, siginfo_t* sig, void* c)
{ 
	write(1, "\nAyyyy...\n", 10);
}

int main()
{
	struct sigaction act;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;
	
	sigaction(SIGINT, &act, NULL);
	while(1)
	{
		printf("looooop\n");
		sleep(2);	
	}
}
