#include <stdio.h>
#include <stdlib.h>
#include "bitOperation.h"

int main()
{
    int num, steps, i, x, p, n, y,w,j,value;
    int result;

    while(1)
	{
        printf("BIT Operation \n");
		printf("1:function inverts the bits  \n");
        printf("2:function that rotates  \n");
		printf("3:function setbits(x,p,n,y)  \n");
		printf("4:function setbits(w,i,j,value) that sets the bits from i to j\n");
        printf("0: exit\n\n");

		scanf("%d", &i);
		switch(i)
        {
            case 1:
                printf("Enter number: ");
				scanf("%d", &num);
				result = inversBits(num);
				printf("Result: ");
				int2Bin(result);
                break;
            case 2:
                printf("Enter number: ");
				scanf("%d", &num);
                printf("Enter steps rotate: ");
				scanf("%d", &steps);
				result = bitRotate(num, steps);
				printf("Result (rotate left) : ");
				int2Bin(result);
               
                break;
            case 3:
                
                printf("Enter number (x,p,n,y): ");
                scanf("%d%d%d%d", &x,&p,&n,&y);
                result = setBits1( x, p, n, y);
                printf("Result: ");
				int2Bin(result);
                    
                
                break;
            case 4:
               printf("Enter number (w,i,j,value): ");
                scanf("%d%d%d%d", &w,&i,&j,&value);
                result = setBits2( w,i,j,value);
                printf("Result: ");
				int2Bin(result);
                break;
            case 0:
                return 0;
            
            printf("\n");

        }

    }

}