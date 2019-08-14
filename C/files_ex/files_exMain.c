#include <stdio.h>
#include <stdlib.h>
#include "files_ex.h"

int main()
{
	int result, N = 0, i=0;
	char fName[32];
	
	while(1)
	{
		printf("enter number of ex:\n");
		printf("1: Exercise 1\n");
		printf("2: Exercise 2\n");
		printf("3: Exercise 3\n");
		printf("4: exit \n");
		
		scanf("%d", &i);
		switch(i)
		{
			case 1:
                /*
                    printf("Enter name of file: \n");
                    scanf("%s", fileName);
                */
				
				printf("Enter N: \n");
				scanf("%d", &N);
				
				result = last(N);
				
				break;
				
			case 2:				
				 /*
                    printf("Enter name of file: \n");
                    scanf("%s", fileName);
                */
				
				result = freqChar();
				
				break;
				
			case 3:
				/*
                    printf("Enter name of file: \n");
                    scanf("%s", fileName);
                */
				
				/*result = freqWords();*/				
				break;
            case 4:
				return 0;				
		}
	}
	
	return 0;
}
