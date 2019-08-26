#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

unsigned long hashFunction(unsigned char* str);
int compareElementsFunction(void* key1, void* key2);
void printHashTable();
int testInsert(hashTable* hashT);
int testSearch(hashTable* hashT);
int testDelete(hashTable* hashT);

int main()
{
    int i = 1, value, result, option, size;
    hashTable* hashT;
    hashFunc hashF = hashFunction;
    compareElementsFunc compareF = compareElementsFunction;
    
    printf("Enter size of hash table \n");
    scanf("%d", &size);
    
    result = createHashTable(hashT, size, hashF, compareF);

    while(i)
    {
        printf("\n Choose option:\n");
		printf("1: Insert \n");
		printf("2: Search \n");
        printf("3: Delete \n");
        printf("4:  \n");
		printf("0 - stop\n");
		
		scanf("%d", &option);
		switch(option)
		{
            case 1:
                result = testInsert(hashT);
                break;
            case 2:
                result =testSearch(hashT);
                break;
            case 3:
                result =testDelete(hashT);
                break;
            case 4:
                break;
            default:
                i = 0;
                break;
        }
    }

    return 0;
}
/*--------------------------------------------------*/
int compareElements(void* key1, void* key2)
{
    char* str1;
    char* str2;

    str1 = (char*)key1;
    str2 = (char*)key2;

    return strcmp(str1, str2);
}
/*--------------------------------------------------*/
unsigned long hashFunction(unsigned char* str)
{
    unsigned long hash = 5381;
    int c;
    while(c= *str++)
    {
        hash = ((hash << 5) + hash) +c;
    }
    return hash;
}
/*--------------------------------------------------*/
int testInsert(hashTable* hashT)
{
    /*insertHashTable(hashTable* hashT, void* key, void* value);*/
    return 0;
}
/*--------------------------------------------------*/
int testSearch(hashTable* hashT)
{

    return 0;
}
/*--------------------------------------------------*/
int testDelete(hashTable* hashT)
{

    return 0;
}
