#include <stdio.h>
#include <stdlib.h>
#include "darray_int.h"

struct darray{

	int* array;
	int index;
	int capacity;
};

static void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

AdtStatus darrayCreate(darray **dArr, size_t initial_capacity)
{

	(*dArr) = malloc(sizeof(darray));
	if(*dArr==NULL)
	{
		return AllocationError;
	}

	(*dArr)->array = malloc(sizeof(int)*initial_capacity);
	if((*dArr)->array == NULL)
	{
		return AllocationError;
	}
	(*dArr)->index = 0;
	(*dArr)->capacity = initial_capacity;


    return OK; 
}

AdtStatus darrayDestroy(darray *dArr)
{
	if(dArr!=NULL)
	{
		return AllocationError;
	}
	free(dArr->array);
	free(dArr);
	return OK; 
}

AdtStatus darrayAdd(darray *dArr,  int  _item)
{
	if(dArr==NULL)
	{
		return AllocationError;
	}

	if(dArr->index == dArr->capacity)
	{
		int* temp;

		temp = dArr->array;
		dArr = realloc(dArr->array, dArr->capacity*sizeof(int));
		if(dArr->array == NULL)
		{
			dArr->array = temp;
			return AllocationError;
		}

		dArr->capacity = (dArr->capacity)*2;

	}

	dArr->array[dArr->index] = _item;
	(dArr->index)++;

	return OK;
}
/*
AdtStatus   darrayDelete(darray *dArr,  int* _item);
*/

AdtStatus darrayGet(darray *dArr, size_t _index, int *_item)
{
	if(dArr==NULL)
	{
		return AllocationError;
	}
	*_item = dArr->array[_index] ;
	
	return OK;
}

AdtStatus darraySet(darray *dArr, size_t _index, int  _item)
{
	if(dArr==NULL)
	{
		return AllocationError;
	}
	if(_index <= dArr->index)
	{
		dArr->array[_index] = _item ;
	}
	return OK;
}
/*AdtStatus   darrayItemsNum(darray *dArr, int*  _numOfItems);
*/
AdtStatus darraySort(darray *dArr)
{
	int i, j;
	int arraySize = dArr->index;
	if(dArr==NULL)
	{
		return AllocationError;
	}

	for(i=0 ; i < arraySize-1 ; i++)
	{
		for(j=0 ; j < arraySize-1 ; j++)
		{
			if(dArr->array[j]> dArr->array[j+1])
			{	
				swap(&dArr->array[j], &dArr->array[j+1]);
			}
		}
	}
}

