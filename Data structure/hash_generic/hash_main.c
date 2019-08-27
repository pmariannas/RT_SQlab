#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

unsigned long hashFunction(void* key);
int compareElementsFunction(void* key1, void* key2);
void printHashTable();

int testInsert(HashTable* hashT);
int testSearch(HashTable* hashT);
int testDelete(HashTable* hashT);
/*--------------------------------------------------*/
int compareElementsFunction(void* key1, void* key2)
{
    char* str1;
    char* str2;

    str1 = (char*)key1;
    str2 = (char*)key2;

    return strcmp(str1, str2);
}
/*--------------------------------------------------*/
unsigned long hashFunction(void* key)
{
    char* str;
    int c;

    unsigned long hash = 5381;
    str = (char*)key;

    while(c= *str++)
    {
        hash = ((hash << 5) + hash) +c;
    }
    return hash;
}
/*--------------------------------------------------*/


int main()
{
    int i = 1, value, result, option, size;
    HashTable* hashT;
    hashFunc hashF ;
    compareElementsFunc compareF;

    hashF = hashFunction;
    compareF = compareElementsFunction;
    
    /*printf("Enter size of hash table \n");
    scanf("%d", &size);*/
    size = 10;
    result = createHashTable(&hashT, size, hashF, compareF);
    printf("!!!!!!!!!!!!!!!!!!!!! %d\n", result);
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
                /* result =testSearch(hashT);*/
               
                break;
            case 3:
                /*result =testDelete(hashT);*/
                
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

int testInsert(HashTable* hashT)
{
    int i, key, result; 
    int value;
    key = 12345;
    value = 2019;
    result = insertHashTable(hashT, &key, &value);
    printf("!????????????????????????%d\n", result);
    return 0;
}


/*--------------------------------------------------*/
int testSearch(HashTable* hashT)
{

    return 0;
}
/*--------------------------------------------------*/
int testDelete(HashTable* hashT)
{

    return 0;
}
