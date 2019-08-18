#include <stdio.h>

void sortArr();
void swap();

int main()
{
    int sizeArr = 6;
    int i,element, arr[6];
   
    printf("enter elements to fill the array (6 numbers):\n");
    for ( i = 0; i < sizeArr; i++)
    {
        scanf("%d", &element);
        arr[i] = element;
    }
    
    
    sortArr(sizeArr,&arr);

    for(i = 0; i < sizeArr; ++i)
	{
		printf("%d ", arr[i]);
	}
    
    return 0;
}

void sortArr(int sizeArr, int* arr)
{
    int i, j;	
	
	for(i = 0; i < sizeArr - 1; ++i)
	{
		for(j = 0; j < sizeArr - 1 - i; ++j)
		{
			if(arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
		
	}
}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}