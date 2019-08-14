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

int isNumber(char* str)
{
    int len = strlen(str);  
    int count=0, i;
    for(i=0 ; i<len; i++)
       {
           if(isdigit(str[i]))
           {
               count++;
           }
           else
           {
               return -1;
           }
           
       }
   return 0;
}

int isString(char* str)
{
    int len = strlen(str);  
    int count=0, i;
    for(i=0 ; i<len; i++)
       {
           if(isalpha(str[i]))
           {
               count++;
           }
           else
           {
               return -1;
           }
       }
    return 0;
}
