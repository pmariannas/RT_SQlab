#ifndef H_HASH
#define  H_HASH


typedef enum  {OK, AllocationError,WrongInput, NullPointer, NotFound, Failed} AdtStatus;

typedef struct HashTable HashTable;

typedef unsigned long (*hashFunc)(void* key);
typedef int (*compareElementsFunc)(void* key1, void* key2);
typedef void (*foreachFunc)(void* key, void* value);
typedef void (*elementDestroyFunc)(void* key, void* value);


AdtStatus createHashTable(HashTable** hashT, size_t size, hashFunc hashF, compareElementsFunc compF);
AdtStatus insertHashTable(HashTable* hashT, void* key, void* value);
AdtStatus desroyHashTable(HashTable* hashT, elementDestroyFunc destroyF);
/*AdtStatus findHashTable(HashTable* hashT, void* key, void** value); */
AdtStatus forEachHashTable(HashTable* hashT, foreachFunc forEF);

#endif
