#include <stdlib.h>
#include "hash.h"


typedef struct {
	Node** list;
    size_t size;
    hashFunc hashF;
    compareElementsFunc compareF;

}hashTable;

typedef struct {
	void* key;
    void* value;
	struct Node* next;

}Node;

AdtStatus createNode(Node** node, void* key, void* value);
AdtStatus addNode(Node** list, void* key, void* value);
AdtStatus destroyNode(Node* node);

/*---------------------------------------------------------*/
AdtStatus createHashTable(hashTable** hashT, size_t size, hashFunc hashF, compareElementsFunc compareF);
{

    if(size <= 0)	
        {
            return WrongInput;
        }
    
    (*hashT) = (hashTable*)calloc(1, sizeof(hashTable));
   
    if(hashT==NULL)
    {
        return AllocationError;
    }

    (*hashT)-> list = (Node**)malloc(size*1.5*sizeof(Node*));

    if((*hashT)-> list == NULL)
    {
        free(*hashT);
        return AllocationError;
    }

    (*hashT)->size = 1.5*size;
    (*hashT)->hashF = hashF;
    (*hashT)->compareF = compareF;

    return OK;
}

/*---------------------------------------------------------*/
AdtStatus insertHashTable(hashTable* hashT, void* key, void* value);
{
    Node* node;
    unsigned long indexBucket = (hashT->hashF(key)) % (hashT->size);
    if(hashT == NULL)
    {
        return NullPointer;
    }
    node =(Node*)malloc(sizeof(Node));
    if(node==NULL)
    {
        return AllocationError;
    }
    
    if(hashT->list[indexBucket]== NULL)    /*if bucket is empty - first element*/
    {
        node->key = key;
        node->value = value;
        hashT->list[indexBucket] = node;
    }
    else
    {
        findElementInList(hashT,key,value);
    }
    
    
     

}
/*---------------------------------------------------------*/
AdtStatus findElementInList(hashTable* hashT, void* key, void* value)
{
    Node* node;
    unsigned long indexBucket = (hashT->hashF(key)) % (hashT->size);

    if(hashT == NULL)
    {
        return NullPointer;
    }

    findNodeInList();
    return node;
}

