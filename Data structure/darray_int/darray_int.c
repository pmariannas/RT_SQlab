#include <stdio.h>
#include <stdlib.h>
#include "darray_int.h"

darray{
	
	int* array;
	int index;
	int capacity;

}
void swap(int* x, int* y);


AdtStatus darrayCreate(darray **dArr, size_t initial_capacity)
{

	*dArr = malloc(sizeof(darray));
	if(*dArr==NULL)
	{
		return AllocationError;
	}

	*dArr->array = malloc(sizeof(int)*initial_capacity);
	if(*dArr->array == NULL)
	{
		return AllocationError;
	}
	*dArr->index = 0;
	*dArr->capacity = initial_capacity;


    return OK; 
}

AdtStatus darrayDestroy(darray *dArr)
{
	if(dArr!=NULL)
	{
		return AllocationError;
	}
	free(dArr->arr);
	free(dArr);
	return OK; 
}

AdtStatus darrayAdd(darray *dArr,  int  _item)
{
	if(*dArr==NULL)
	{
		return AllocationError;
	}

	if(dArr->index == dArr->capasity)
	{
		int* temp;

		temp = dArr->arr;
		dArr = realloc(dArr->arr, dArr->capacity*sizeof(int));
		if(dArr->arr == NULL)
		{
			dArr->arr = temp;
			return AllocationError;
		}

		dArr->capasity = dArr->capasity)*2;

	}

	dArr->arr[dArr->index] = _temp;
	(dArr->index)++;

	return OK;
}
/*
AdtStatus   darrayDelete(darray *dArr,  int* _item);
*/

AdtStatus   darrayGet(darray *dArr, size_t _index, int *_item)
{
	if(*dArr==NULL)
	{
		return AllocationError;
	}
	_item = dArr->arr[_index] 
	
	return OK;
}

AdtStatus   darraySet(darray *dArr, size_t _index, int  _item)
{
	if(*dArr==NULL)
	{
		return AllocationError;
	}
	if(_index <= dArr->index)
	{
		dArr->arr[_index] = _item ;
	}
	return OK;
}
/*AdtStatus   darrayItemsNum(darray *dArr, int*  _numOfItems);
*/
AdtStatus darraySort(darray *dArr, size_t arraySize)
{
	int i, j;
	if(*dArr==NULL)
	{
		return AllocationError;
	}

	for(i=0 ; i < arraySize-1 ; i++)
	{
		for(j=0 ; j < arraySize-1 ; j++)
		{
			if(dArr->arr[j]> dArr->arr[j+1])
			{	
				swap(&dArr->arr[j], &dArr->arr[j+1]);
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
