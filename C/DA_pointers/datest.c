#include <stdio.h>
#include <stdlib.h>
#include "da.h"

int main()
{
    int capacity=0, flag=1, /*num=0*/ value;
    int* nPtr=NULL;
    Da_t* da;
    nPtr = 0;
    printf("Enter capacity: ");
    scanf("%d", &capacity);  

    da = createDA(capacity);
    
    if(da!=NULL)
    {
        printf("Enter element to insert: \n (stop inser- press 999)\n");
        nPtr =malloc(capacity * sizeof(int*));
        scanf("%d", nPtr);

        while (*nPtr!=999)
            {
                insertDA(da, nPtr);
                nPtr = malloc(capacity * sizeof(nPtr));
                printf("Enter element to insert:");
                scanf("%d", nPtr);
               
            }

        printDA(da);
        destroyDA(da);
    }
    
    
    return 0;
}

