#include <stdio.h>
#include <stdlib.h>
#include "bitMap_ex.h"

int main()
{
    unsigned int nf , i, n, binNum;
    int errorCheck, result;
    bitMap_t* bm;
	bitFunc func[3] = {bitOn, bitOff, bitStatus};

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
                result =  callFunc(func[0], bm, n);
                if(result == -1)
                {
                    printf("error");
                }
                break;
            case 2:
                printf("enter bit to off: \n");
                scanf("%u", &n);
                result = callFunc(func[1], bm, n);
                if(result == -1)
                {
                    printf("error");
                }
                break;
            case 3:
                printf("enter bit to check status: \n");
                scanf("%u", &n);
                result = callFunc(func[2], bm, n);
                if(result == -1)
                {
                    printf("error");
                }
                else if (result == 0)
                {
                    printf("Bit %u Status: OFF\n", n);
                }
                else
                {
                    printf("Bit %u Status: ON\n", n);
                }
                
                break;
            case 4:
                result = printBitMap(bm);
                if(result == -1)
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
