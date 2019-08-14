#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char* arg1 = argv[1];
    char* arg2 = argv[2];

    if(argc == 3)     
    {
        if(isNumber(arg1)==0 && isString(arg2)==0 )
        {
            printf("age:%d name:%s\n",  atoi(arg1), arg2);
        }
        else if(isNumber(arg2)==0 && isString(arg1)==0 )
        {
            printf("age:%d name:%s\n",  atoi(arg2), arg1);
        }
        else 
        {
            printf("error\n");    
        }        
    }

}

int isNumber(char* arg1)
{
    int len1 = strlen(arg1);  
    int count=0, i;
    for(i=0 ; i<len1; i++)
       {
           if(isdigit(arg1[i]))
           {
               count++;
           }
           else
           {
               return -1;
           }
           
       }
    if(count==len1)
    {
        return 0;
    } 
}

int isString(char* arg1)
{
    int len1 = strlen(arg1);  
    int count=0, i;
    for(i=0 ; i<len1; i++)
       {
           if(isalpha(arg1[i]))
           {
               count++;
           }
           else
           {
               return -1;
           }
           
       }
    if(count==len1)
    {
        return 0;

    } 
}
