#ifndef H_HASH
#define  H_HASH


typedef enum  {OK, AllocationError,WrongInput, NullPointer, NotFound} AdtStatus;

typedef struct HashTable HashTable;

typedef unsigned long (*hashFunc)(void* key);
typedef int (*compareElementsFunc)(void* key1, void* key2);


AdtStatus createHashTable(HashTable** hashT, size_t size, hashFunc hashF, compareElementsFunc compF);
AdtStatus insertHashTable(HashTable* hashT, void* key, void* value);
/*
AdtStatus findHashTable(HashTable* hashT, void* key, void* value); 
AdtStatus desroyHashTable(HashTable* table); 
*/

/*
AdtStatus forEachHashTable(hashTable* hashT);
*/

#endif
