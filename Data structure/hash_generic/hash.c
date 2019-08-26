#include <stdlib.h>
#include "hash.h"

static void hashFunc(hashTable *table, elementCompare compareFunc);

typedef struct {
	void** list;
    int size;
    elementCompare compareFunc;
}hashTable;

typedef struct {
	void* key;
    void* value;
	struct Node* next;

}Node;




HashTStatus hashtableCreate(int size)
{
    hashTable* ht;


    if(size <= 0)	
        {
            return WrongInput;
        }
    
    ht = malloc(2*size*sizeof(hashTable));
   
    if(ht==NULL)
    {
        return AllocationError;
    }

    ht->size = 2*size;
    ht-> list = NULL;

    return OK;
}

HashTStatus hashtableInsert(hashTable* ht, void* key, void* value, hashFunc hashFunc)
{
    hashTable* ht;
    Node* node;
    size_t indexBucket = hashFunc(key) % ht->size ;

    node = malloc(sizeof(Node));
    if(node==NULL)
    {
        return AllocationError;
    }

    node->key = key;
    node->value = value;

    findElement(node, ht[indexBucket]->list);
     



}

AdtStatus findElement(hashTable* ht, Node** search,void* key)
{
    Node* node;

    while(node)
    {   
        if(node->key == key)
        {

        }
        node = node->next;
    }
    return node;
}

