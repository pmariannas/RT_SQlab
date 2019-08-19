#include <stdio.h>
#include <stdlib.h>

int* insertFunc(int num,int* ptr, int* index,int* cap);

int main()
{
    int sizeArr, num=0, *ptr, index=0, cap, i=0;
    printf("Enter number of elements: ");
    scanf("%d", &sizeArr);
    ptr = (int*) malloc(sizeArr * sizeof(int));
    
    cap = sizeArr;

    if(ptr == NULL)                     
    {
        printf("Error! memory not allocated.");
        exit(0);
    }
/* while (num!=99)
    {
        printf("Enter elements:");
        scanf("%d", &num);
        insertFunc(num, ptr,&index, &cap);
    }
    */
   
    /*print array*/
    for(i=0; i<cap; i++)
    {
        printf("%d\n", ptr[i]);
    }
    
    free(ptr);
    return 0;
}

int* insertFunc(int num,int* ptr, int* index,int* cap )
{
    int *temp=ptr;
    if (*index==*cap)
    {
       temp = (int*)realloc(ptr,sizeof(int)*((*cap)*2));
        if(ptr != NULL)                     
            {
                ptr=temp;
                *cap *=2;
            }
        else
        {
            return ptr;
        }
        
    }
    ptr[(*index)]=num;
    *index++;

    return ptr;
}