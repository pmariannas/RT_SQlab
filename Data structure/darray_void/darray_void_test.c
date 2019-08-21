#include <stdio.h>

#include "darray_void.h"

typedef struct {
	int _x;
	int _y;

}Point;

void destroyFunc1(void* _elemA , void* context)
{
	FILE* fp =(FILE*)context;

	Point* tempPerson = (Point*)_elemA;
	if(fp == NULL)
	{
		printf("Error!");   
	}
	fprintf(fp," x:%d y:%d",tempPerson->_x, tempPerson->_y);
   	fclose(fp);
	free(tempPerson);

}

/*void (* elementCompare)(void *_elemA, void *_elemB);*/


int main()
{
	int i;
	darray *myDarray;
	FILE* fp = fopen("fileDelete.txt","a");
	Point itemToSend;
	int x,y;
		

	darrayCreate(&myDarray, 100); 

	scanf("%d", &i);
	printf("1 - darray Add\n");
	printf("2 - darray Get\n");
	printf("3 - darray Set\n");
	printf("4 - darray Sort\n");
	printf("5 - darray Destroy\n");




	switch (i)
	{
	case 1: /*darrayAdd*/
		
		printf("enter x\n");
		scanf("%d", &x);
		itemToSend._x = x;
		
		printf("enter y\n");
		scanf("%d", &y);
		itemToSend._y =y;
		
		darrayAdd(myDarray, &itemToSend);

		break;
	
	case 2:
	
		darrayGet(myDarray, myDarray->_index, point)
		break;
	
	case 3:
		
		break;
	case 4:
	
		break;
	case 5:
		darrayDestroy(myDarray, destroyFunc1, fp );
		break;
	default:
		break;
	}
	
	/*
	darrayGet(darray *dArr, size_t _index, int *_item);
	darraySet(darray *dArr, size_t _index, int  _item);
	darraySort(darray *dArr);
	
	*/
	

}
