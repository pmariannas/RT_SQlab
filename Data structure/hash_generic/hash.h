#ifndef H_HASH
#define H_HASH


typedef enum  {OK, AllocationError,WrongInput} AdtStatus;
AdtStatus hashtableCreate(int size, hashFunc hashFunc);
AdtStatus hashtableInsert(void* key, void* value);
void* hashtableFind(void* key);
void* hashtableDesroy(void* key, hashTable* table);
/*
void* hashtableForEach();
*/

#endif