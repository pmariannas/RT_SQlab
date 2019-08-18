#include <stdio.h>
#include <stdlib.h>
#include "bitOperation.h"

void int2Bin(int n)
{
	int i = 0, binNum=0;
	
    for (i = (sizeof(char)*8-1) ; i >= 0 ; i--)
	{
		binNum = n >> i;
		if(binNum & 1)
		{
			printf("1");
		}		  
		else
		{
			printf("0");

		}
	}
	printf("\n");
}

int inversBits(int n)
{
	return n^255;
}

int bitRotate(int n, int steps)
{
	return (n << steps)|(n >> (8 - steps)); 
}

int setBits1(int x, int p, int n, int y)
{
	int i=0;
    
    for(i=p ; i <= 8 && (n+i-p-1)<=7 ; i++)
    {   
        x = x & ~(128 >> (n+i-p-1));
        if ((y & (128 >> (i-1)))!=0) 
        {
            x = x | (128 >> (n+i-p-1));
        }
    }
	
	return x;
}

int setBits2(int w, int i, int j, int value)
{

	
	return 0;
}

