#include <stdio.h>
#include <string.h>
/*---1---*/
/*
int i;
int increment(int i)
{
    i++;
}
int main()
{
    for(i = 0; i<10 ; increment(i))
    {

    }
    printf("i=%d\n", i);
    return 0;
}
*/
/*---2---*/
/*
int main()
{
    int array[13] = {7,5,7,8,3,4,9,0,0,2,8,5,1};
    int i, j;
    int arrayCount[10];
    for(i = 0 ; i<10 ; i++)
    {
        arrayCount[i] = 0;
    }
    for(i = 0 ; i<13 ; i++)
    {
        j = array[i];
        arrayCount[j]++;
    }
    for(i = 0 ; i<10 ; i++)
    {
        printf("%d : %d  \n", i, arrayCount[i]);
    }
    return 0 ;
}
*/
/*---3---*/
/*
int main()
{
    int y[4] = {6,7,8,9};
    int* ptr =y+2;
    printf("%d\n", ptr[1]);
    return 0;
}
*/
/*---4---*/
/*
int main()
{
    int i=4;
    switch(i)
    {
        default:
            ;
        case 3:
            i+=3;
            break;
        case 8:
            i+=5;
            break;
    }
    printf("i = %d\n", i);
    return 0;
}
*/
/*---5---*/
/*
int main()
{
    int x[] = {1,2,3,4,5};
    int i;
    int* ptr = x;

    *(ptr+3) = 10;

    for(i = 0 ; i<5 ; i++)
    {
        printf("%d \n", x[i]);
    }
    return 0;
}
*/

/*---6---*/
/*
int *f1(void)
{
    int x = 10;
    return &x;
}

int *f2(void)
{
    int *ptr = 0;
    *ptr = 10;
    return 0;
}
*/

/*---7---*/
/*
int main()
{
    int x[] = {1,4,8,5,1,4};
    int *ptr, y;
    ptr = x+4;
    y = ptr-4;
    printf("%d \n", y);
    return 0;
}
*/

/*---8---*/
/*
int main()
{   
    int array[] = {1,2,3,4,5,10,9,8,7};
    int n = 10;
    int sum = 0;
    int numOfnum = 0;
    int i;
    for(i = 1; i <= n ; i++)
    {
        numOfnum += i;
    }
    for(i = 0; i < n-1; i++)
    {
        sum += array[i];
    }
    printf("%d \n",numOfnum-sum);
    return 0;
}
*/
/*---9---*/


/*---10---*/
int strIndex(char* str1, char* str2)
{
    int pos = 0;
    int i, j;
    printf("%s %s %ld\n", str1, str2, strlen(str1));
    if(str1 == NULL || str2 == NULL)
    {
        return -1;
    }
    if(strlen(str1)==0)
    {
        return -1;
    }
    if(strlen(str2) > strlen(str1))
    {
        return -1;
    }
    for(i=0 ; i< strlen(str1) ; i++)
    {
        pos = i;
        for(j = 0 ; j< strlen(str2) ; i++)
        {
            if(str1[i]==str2[j])
            {
                i++;
                if(i==strlen(str2))
                {
                    return pos;
                }
            }
        }
    }
    return -1;
}

int main()
{
    int result = 0;
    char* str1 = "marianna";
    char* str2 = "marianna";
    result = strIndex(str1, str2);
    printf("%d \n", result);
    return 0;
}
/*-----------------------------------------*/











































