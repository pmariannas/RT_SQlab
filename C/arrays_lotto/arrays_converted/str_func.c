#include <stdio.h>
#include <string.h>

void mystrCopy(char* str1, char* str2 )
{
    int i, lenStr;
    lenStr = strlen(str1);

    for (i=0; i<lenStr; i++)
    {
        str2[i]=str1[i];
    }
    
    str2[lenStr]='\0';
}

void mystrCat(char* str1, char* str2)
{
    char str[80];
    int i, j, lenStr1, lenStr2;
    lenStr1 = strlen(str1);
    lenStr2 = strlen(str2);


    str1[lenStr1+1]=' ';
    for(j=0; j<=lenStr2; j++)
    {
        str1[lenStr1]=str2[j];
        lenStr1++;
    }

    
    str1[lenStr1+lenStr2]='\0';
}

int main()
{
    
    char str1[]="Sample string"; /*strint to copy*/
    char str2[32]; 
    mystrCopy(str1, str2);
    printf("copy successful: %s\n", str2);

    mystrCat(str1, str2);
    printf("copy successful: %s\n", str1);

    return 0;
}

