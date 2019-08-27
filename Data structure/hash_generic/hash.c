#include <stdlib.h>
#include "hash.h"
#include <stdio.h>
typedef struct Node Node;
struct Node{
	void* key;
    void* value;
	struct Node* next;

};
struct HashTable{
	Node** list;
    size_t size;
    hashFunc hashF;
    compareElementsFunc compareF;
    int countNode;
};


 

/*AdtStatus createNode(Node** node, void* key, void* value);*/
/*AdtStatus addNode(Node** list, void* key, void* value);*/
/*AdtStatus destroyNode(Node* node);*/
AdtStatus findElementInList(HashTable* hashT, void* key, void* value, Node** prev, Node** curr);


/*---------------------------------------------------------*/
AdtStatus createHashTable(HashTable** hashT, size_t size, hashFunc hashF, compareElementsFunc compareF)
{

    if(size <= 0)	
    {
        return WrongInput;
    }
    
    (*hashT) = (HashTable*)malloc(sizeof(HashTable));
   
    if(hashT==NULL)
    {
        return AllocationError;
    }

    (*hashT)-> list = (Node**)calloc(size*1.5,sizeof(Node*));

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
AdtStatus insertHashTable(HashTable* hashT, void* key, void* value)
{
    Node* node;
    Node* temp;
    Node* prev;
    Node* curr;
    AdtStatus status;
    unsigned long indexBucket;
    if(hashT == NULL)
    {
        return NullPointer;
    }

    indexBucket = ((hashT)->hashF(key))%((hashT)->size);
    (curr) = (hashT)->list[indexBucket];
    (prev) = (curr);
    
    
    node =(Node*)malloc(sizeof(Node));

    if(node==NULL)
    {
        return AllocationError;
    }

    if((curr) == NULL)    /*if bucket is empty - first element*/
    {
        node->key = key;
        node->value = value;
        node->next = NULL;
        (hashT)->list[indexBucket] = node;
    }
    else
    {
        status = findElementInList(hashT, key, value, &prev, &curr);
        if(status==NotFound)
        {
            node->key = key;
            node->value = value;

            temp = (curr);
            (curr)->next = node;
            node->next = temp->next;

            status = OK;
        }
    }
    status = 0;
    return status;
     

}
/*---------------------------------------------------------*/
AdtStatus findElementInList(HashTable* hashT, void* key, void* value, Node** prev, Node** curr)
{
    if((hashT) == NULL)
    {
        return NullPointer;
    }

    while((*curr)!=NULL)
    {
        
        if((hashT)->compareF((*curr)->key, key)==0)
        {
            /*uodate value*/
            (*curr)->value = value;
            return OK; /*found and update*/

        }
        else
        {
            (*prev) = (*curr);
            (*curr) = (*curr)->next;
        }
    }
    return NotFound;
}

