#ifndef H_HASH
#define  H_HASH


typedef enum  {OK, AllocationError,WrongInput, NullPointer} AdtStatus;

typedef struct hashTable hashTable;
typedef struct Node Node;

typedef unsigned long (*hashFunc)(void* key);
typedef int (*compareElementsFunc)(void* key1, void* key2);


AdtStatus createHashTable(hashTable** hashT, size_t size, hashFunc hashF, compareElementsFunc compF);
AdtStatus insertHashTable(hashTable* hashT, void* key, void* value);
AdtStatus findHashTable(hashTable* hashT, void* key, void* value); /*???*/
AdtStatus desroyHashTable(hashTable* table); /*???*/
/*
AdtStatus forEachHashTable(hashTable* hashT);
*/

#endif
