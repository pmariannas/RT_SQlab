#include <stdio.h>

void sortArr();
void swap();

int main()
{
    int sizeArr = 10;
    int i,j, element, arr[10];
   
    printf("enter 0 or 1:\n");
    for ( i = 0; i < sizeArr; i++)
    {
        scanf("%d", &element);
        arr[i] = element;
    }
    
    
    sortArr(sizeArr,&arr);
    
    return 0;
}

void sortArr(int sizeArr, int* arr)
{
    int i, temp;
    
    for ( i = 0; i < sizeArr; i++)
    {
        printf("%d", arr[i]);
    }
    
    for(i=0; i<sizeArr-1; i++)
    {
        if (arr[0]>arr[i+1])
        {
            int temp;
            i=i+1;
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1]=temp;
        }
    }

    for ( i = 0; i < sizeArr; i++)
    {
        printf("%d", arr[i]);
    }
}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
