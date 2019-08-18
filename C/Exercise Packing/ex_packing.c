#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ex_packing.h"

static void int2Bin(int num)
{
	int i = 0, binNum=0;
	
    for (i = 8-1 ; i >= 0 ; i--)
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
    printf("\n");
}

/*without bit field option*/
int compressWithout(char* mystr)
{
    int i;
    int lenStr = strlen(mystr);
    for ( i = 0; i < lenStr; i++)
    {
        mystr[i] = (mystr[i] - 'a')<<4;
        mystr[i] = (mystr[i] | (mystr[i+1] - 'a'));
        i++;

    }
    
/*ex1*/
/*
 str[0] = (str[0] - 'a')<<4;
    str[0] = str[0] | (str[1] - 'a');
    str[1] = (str[1] - 'a')<<4;
    str[1] = str[1] | (str[2] - 'a');
   
*/
    return strlen(mystr);
   

}

/*with bit field option – use struct and union*/
int compressUn(union un Union, char* mystr)
{
    int i, result;
    int lenStr = strlen(mystr); 
    
    for ( i = 0; i < lenStr; i++)
    {
        Union.lr.left = (mystr[i]-'a');
        Union.lr.right = (mystr[i+1]-'a');
        mystr[i] = Union.c;
        i++;
    }
    
    return strlen(mystr);
}