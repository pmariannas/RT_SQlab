#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

unsigned long hashFunction(void* key);
int compareElementsFunction(void* key1, void* key2);
void destroyFunction(void* key, void* value);
void forEachFunction(void* key, void* value);


int testInsert(HashTable* hashT);
int testSearch(HashTable* hashT);
int testDestroy(HashTable* hashT);
int testPrintHashTable(HashTable* hashT);
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
void destroyFunction(void* key, void* value)
{
    printf("Destroy: key-> %s , value-> %s \n", (char*)key, (char*)value);

}
/*--------------------------------------------------*/
void forEachFunction(void* key, void* value)
{
    printf(" { key = %s ,  value = %s } ", (char*)key, (char*)value);
}

/*-------------------MAIN FUNCTION-------------------*/
int main()
{
    int i = 1, value, result, option, size;
    HashTable* hashT;
    hashFunc hashF ;
    compareElementsFunc compareF;

    hashF = hashFunction;
    compareF = compareElementsFunction;
    
    size = 50;
    result = createHashTable(&hashT, size, hashF, compareF);

    if(result == OK)
    {
        printf(" Hash Table created Successfully\n");
    }

    while(i)
    {
        printf("\n Choose option:\n");
		printf("1: Insert \n");
		printf("2: Search \n");
        printf("3: Delete \n");
        printf("4: Print \n");
        printf("5:  \n");
		printf("0 - stop\n");
		
		scanf("%d", &option);
		switch(option)
		{
            case 1:
                result =  testInsert(hashT);
                break;
            case 2:
                /* result =testSearch(hashT);*/
               
                break;
            case 3:
                result =testDestroy(hashT);
                
                break;
            case 4:
                testPrintHashTable(hashT);
                break;
            case 5:
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
    int i, key,key1, key2, value, value1, result, option; 
    
    /* while(i)
     {*/
        printf("\n Choose option:\n");
		printf("1: Insert empty \n");
		printf("2: Insert 2 elements \n");
        printf("3: Insert 10 element \n");
        printf("4:   \n");
		printf("0 - stop\n");
		
		scanf("%d", &option);
		switch(option)
		{
            case 1:
                result = insertHashTable(hashT, NULL, NULL);
                if(result == 3)
                {
                    printf("NullPointer ERROR\n");

                }
                break;
            case 2:
                result = insertHashTable(hashT, "1234567", "Tel Aviv");
                if(result ==0 )
                {
                    printf("first element - insert success\n");
                }
                result = insertHashTable(hashT, "9876543", "Beer Sheva");
                if(result == 0)
                {
                    printf("second element - insert success\n");
                }
                break;
            case 3:
                result = insertHashTable(hashT, "1234567", "Tel Aviv");
                result = insertHashTable(hashT, "2134567", "Sderot");
                //result = insertHashTable(hashT, "1234567", "Ashkelon");
                result = insertHashTable(hashT, "1094567", "Ashdod");
                result = insertHashTable(hashT, "1212567", "Eilat");
                //result = insertHashTable(hashT, "1983567", "Dimona");
                //result = insertHashTable(hashT, "1299567", "Arad");
                //result = insertHashTable(hashT, "1276557", "Ramat gan");
                //result = insertHashTable(hashT, "1034569", "Bat Yam");
                result = insertHashTable(hashT, "1234567", "Beer Sheva");

                
                /*printf("insert success");*/
                              
                break;
            case 4:
                break;
            default:
                i = 0;
                break;
        }
    /*}*/
    
    
    return 0;
}


/*--------------------------------------------------*/
int testSearch(HashTable* hashT)
{

    return 0;
}
/*--------------------------------------------------*/
int testDestroy(HashTable* hashT)
{
    elementDestroyFunc destroyF = destroyFunction;
    desroyHashTable(hashT, destroyF);

    return 0;
}

int testPrintHashTable(HashTable* hashT)
{
    foreachFunc forEF;
    forEF = forEachFunction;
    
    forEachHashTable(hashT, forEF);

}
