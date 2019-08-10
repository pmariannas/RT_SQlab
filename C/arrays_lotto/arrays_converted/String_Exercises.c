#include <stdio.h>
#include <string.h>

void Int2Bin (unsigned int num);
void Bin2Int (char* binNum);
void reverseString (char* str);
void squeeze (char* str1, char* str2);
void removeChar(char *str, char garbage);
int location (char* str1, char* str2);

int main()
{
    unsigned int num=0; 
    int length=32, i=9, out, task = 0;
    char binStr[32]; /* binary string */
    char str1[32]/* = "ABCDEF"*/;
    char str2[32]/* = "BKE"*/;

    while(i != 0)
    {
    printf("\n\nEnter number of task you want to check:\n 1-Int2Bin\n 2-Int2Bin \n 3-squeeze \n 4-location \n ");
    scanf("%d",&i);

        switch(i)
        {
            case 1: 
                printf("Int2Bin - Decimal to Binary converter\n  Enter number:");
                scanf("%d", &num);
                printf("The binnary number of %d ---> ",num);
                Int2Bin(num);
                printf("\n");
                break;

            case 2:
                printf("Bin2Int - Binary to Decimal converter\n  Enter Binary string: \n");
                scanf("%s", binStr);
                printf("The decimal number of %s ---> ",binStr);
                Bin2Int(binStr);
                printf("\n");
                break;

            case 3:
                printf("Enter string (1):\n");
                scanf("%s", &str1);
                printf("Enter string (2):\n");
                scanf("%s", &str2);
                squeeze(str1, str2);
                printf("\n");
                break;

            case 4:
                printf("Enter string (1):\n");
                scanf("%s", &str1);
                printf("Enter sub string (2):\n");
                scanf("%s", &str2);
                out = location(str1, str2);
                printf("The index of sub string '%s' is %d", str2, out);
                break;
        }
    }
    return 0;
}
 
 void Int2Bin(unsigned int num)
 {
    int i=0, lenStr=0;
    char binNum[32];
   
     while (num!=0)
     {
         if (num%2==0) /*if even write 0 to string*/
         {
            binNum[i]='0';
         }
         else          /*else write 1 to string*/
         {
            binNum[i]='1';
         }

         num = num/2;
         i++;
     }
    
    binNum[strlen(binNum)]= '\0';
    reverseString(binNum);/*call to reverse string function*/
    printf("%s", binNum);
 }

 void Bin2Int(char* binNum)
 {
    int i=0, lenStr=0, num=0, count = 1;

    lenStr = strlen(binNum);
    reverseString(binNum); /*call to reverse string function*/

    for(i=0 ; i<lenStr; i++)
    {   
        if(binNum[i]=='1')
        {
            num += count;
        }
        count *=2;
    }
    printf("%d", num);
 }

void reverseString(char* str) 
{ 
    int lenStr, i; 
    char *startStr, *endStr, temp; 
  
    lenStr = strlen(str); 
    startStr = str; 
    endStr = str; 
  
    for (i = 0; i < lenStr - 1; i++) 
    {
        endStr++; /*move pointer to the end of string*/
    }
  
    for (i = 0; i < lenStr / 2; i++) 
    { 

        /*swap value*/   
        temp = *endStr; 
        *endStr = *startStr; 
        *startStr = temp; 

        startStr++; /*move pointer*/
        endStr--;   /*move pointer*/

    } 
} 

void squeeze(char* str1, char* str2)
{
    int i=0, j=0, lenStr1=0, lenStr2=0;
    lenStr1 = strlen(str1);
    lenStr2 = strlen(str2);

    for ( i = 0; i < lenStr1; i++)
    {
        for ( j = 0; j < lenStr2; j++)
        {
            if (str1[i]==str2[j])
            {
                removeChar(str1, str1[i]);
            }
        }
    }
    printf("String after squeeze : %s\n", str1);
}

void removeChar(char *str, char garbage) 
{
    char *dst;
        
    dst = str;
    for (str ; *str != '\0'; str++) 
    {
        *dst = *str;

        if (*dst != garbage)
        {
            dst++;
        }
    }
    *dst = '\0';
}

int location (char* str1, char* str2)
{
    int i, j, locationStr=-1, lenStr1=0, lenStr2=0;
    lenStr1 = strlen(str1);
    lenStr2 = strlen(str2);

    for (i=0; i < lenStr1  ; i++)
    { 
        locationStr = i;
        for (j=0 ; j < lenStr2 ; j++)
        {   
            
            if(str1[locationStr]==str2[j])
            {
                if(j == lenStr2-1) /*check the end of sub string*/
                    {
                        return i; /*return the first index of sub string in String*/
                    }
                else
                {
                    locationStr++;
                }

            }
        }
    }
    // printf("NOT FOUND");
    return -1;
}