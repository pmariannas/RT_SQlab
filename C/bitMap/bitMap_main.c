#include <stdio.h>
#include <stdlib.h>
#include "bitMap_ex.h"

int main()
{
    unsigned int nf , i, n, binNum;
    int errorCheck;
    bitMap_t* bm;

    printf("enter number of feature: \n");
    scanf("%u", &nf);
    bm = createBitMap(nf);

    while(1)
	{
        printf("\n");
		printf("1: bitOn \n");
		printf("2: bitOff \n");
		printf("3: bitStatus \n");
		printf("4: printBitMap \n");
        printf("0: exit\n\n");

		scanf("%u", &i);
		switch(i)
        {
            case 1:
                printf("enter bit to on: \n");
                scanf("%u", &n);
                errorCheck =  bitOn(bm, n);
                if(errorCheck == -1)
                {
                    printf("error");
                }
                break;
            case 2:
                printf("enter bit to off: \n");
                scanf("%u", &n);
                errorCheck = bitOff(bm, n);
                if(errorCheck == -1)
                {
                    printf("error");
                }
                break;
            case 3:
                printf("enter bit to check status: \n");
                scanf("%u", &n);
                errorCheck = bitStatus(bm, n);
                if(errorCheck == -1)
                {
                    printf("error");
                }
                else if (errorCheck == 0)
                {
                    printf("Bit %u Status: OFF\n", n);
                }
                else
                {
                    printf("Bit %u Status: ON\n", n);
                }
                
                break;
            case 4:
                errorCheck = printBitMap(bm);
                if(errorCheck == -1)
                {
                    printf("error");
                }
                break;
            case 0:
                destroyBitMap(bm);
                return 0;
            
            printf("\n");

        }

    }

}