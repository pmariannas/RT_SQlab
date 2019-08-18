#include <stdio.h>
#include <stdlib.h>
#include "bitOperation.h"

static void int2Bin(int num)
{
	int i = 0, binNum=0;
	
    for (i = countBit-1 ; i >= 0 ; i--)
	{
		binNum = num >> i;
		if(binNum & 1)
		{
			printf("1");
		}		  
		else
		{
			printf("0");
		}
	}
}