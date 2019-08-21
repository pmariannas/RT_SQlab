#include <stdio.h>
#include <stdlib.h>
#include "darray_void.h"

struct darray{

	void** array;
	int index;
	int capacity;
	int initial_capacity;
};


/*
static void swap(void* x, void* y)
{
	void* temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

*/


AdtStatus darrayCreate(darray **dArr, size_t initial_capacity)
{
	if(initial_capacity<=0)	/**/
	{
		return WrongInput;
	}
	(*dArr) = malloc(sizeof(darray));
	if(*dArr==NULL)
	{
		return AllocationError;
	}

	(*dArr)->array = malloc(sizeof(void)*initial_capacity);
	if((*dArr)->array == NULL)
	{
		free(dArr);	/**/
		return AllocationError;
	}

	
	(*dArr)->index = 0;
	(*dArr)->capacity = initial_capacity;
	(*dArr)->initial_capacity = initial_capacity;



    return OK; 
}

AdtStatus darrayDestroy(darray *dArr, elementDestroy destroyFunc1, void *context)
{
	int indexElement = 0;
	if(dArr==NULL)	/*bug in prigram if this if return true*/
	{
		return AllocationError;
	}
	for(indexElement=0 ; indexElement< dArr->index ; indexElement++)
	{
		destroyFunc1(dArr->array[indexElement], context); /*context- file name*/
	}
	free(dArr->array);
	free(dArr);
	return OK; 
}


AdtStatus darrayAdd(darray *dArr,  void*  _item)
{
	if(dArr==NULL)
	{
		return AllocationError;
	}

	if(dArr->index == dArr->capacity)
	{
		void* temp;

		temp = dArr->array;
		dArr = realloc(dArr->array, dArr->capacity*sizeof(void));
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
AdtStatus   darrayDelete(darray *dArr,  void *_item);
*/

AdtStatus darrayGet(darray *dArr, size_t _index, void **_item)
{
	if(dArr==NULL)
	{
		return AllocationError;
	}
	*_item = dArr->array[_index] ;
	
	return OK;
}

AdtStatus darraySet(darray *dArr, size_t _index, void*  _item)
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

/*
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



*/
