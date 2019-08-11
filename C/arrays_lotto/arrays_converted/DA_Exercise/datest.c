#include <stdio.h>
#include <stdlib.h>
#include "da.h"

int main()
{
    int capacity=0, flag=1, num=0, value;
    Da_t* da;

    printf("Enter capacity: ");
    scanf("%d", &capacity);  

    da = createDA(capacity);

    printf("Enter element to insert: \n (for exit from insert press 999)\n");

    scanf("%d", &num);
    while (num!=999)
        {
            value = insertDA(da, num);
            printf("Enter element to insert:");
            scanf("%d", &num);
        }

    printDA(da);
    destroyDA(da);
    return 0;
}
