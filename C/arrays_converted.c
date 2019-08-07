#include <stdio.h>
#include <stdlib.h>
#include<time.h> 


void sortArrayAscending(int* arr , int sizeArr );
void sortArray01();
int occurMost();
void lotto();

int main()
{
    
    printf("1) sortArrayAscending:\n ");
    int sizeArr = 5;
    int arr[] = {3,1,2,5,4};
    sortArrayAscending(arr, sizeArr);
    printf("\n");
    printf("2) sortArray01:\n ");
    sortArray01();
    printf("\n");
    printf("5) occurMost:\n ");
    int arr5[] = {3, 6 ,8 ,3 ,9 ,12, 45, 9 ,12 ,56, 12};
    int sizeArr5 = 11;
    occurMost(arr5, sizeArr5);
    printf("\n");
    printf("LOTTO\n");
    lotto();

    return 0 ;
}

void sortArrayAscending(int* arr, int sizeArr)
{
    int i, j,temp;
    for (i = 0; i < sizeArr; i++) 
        {
            for (j = i + 1; j < sizeArr; j++)
            {
                if (*(arr+i) > *(arr+j)) 
                {
                    temp =  *(arr+i);
                    *(arr+i) = *(arr+j);
                    *(arr+j) = temp;
                }
            }
        }

        /*function print the array*/
        for (i=0; i< sizeArr; i++)
        {
            printf("%d ", *(arr+i));
        }
}

void sortArray01()
{
    int i, j, count0=0, count1=0, sizeArr=10, arr[10]={0,1,0,1,1,1,0,0,0,1};
    
    /*count number of 0 and 1 in array*/
    for(i=0 ; i < sizeArr; i++ )
    {
        if (arr[i]==0)
        {
            count0++;
        }
        else 
        {
            count1++;
        }
        
    }

    /*put 0 and 1 in array */
    for(i=0; i<sizeArr; i++)
    {
        if (i<count0)
        {
            arr[i]=0;
        }
        else
        {
            arr[i]=1;
        }
        
    }
    
    /*function print the array*/
    for (i=0; i< sizeArr; i++)
        {
            printf("%d ", arr[i]);
        }
    
}

int occurMost(int* arr, int sizeArr)
{
    int i, j,ansNum = 0, ansCount = 0, num, countNum;

    for (i = 0; i<sizeArr ; i++ )
    {
        num = *(arr+i);
        countNum = 1;

        for(j = i+1; j< sizeArr; j++)
        {
            if (*(arr+i)==*(arr+j))
            {
                countNum++;
            }
        }

        if (ansNum !=num && ansCount < countNum)
        {
            ansNum = num;
            ansCount = countNum; 
        }
    }
    printf("%d, occur %d times\n", ansNum, ansCount);
    return 0 ;
}

void lotto()
{
    /* random numbers*/
    int arrRandomNum[6] = {2, 13,15,37,39, 41} ;

    /*This program will create different sequence of */  
    /*random numbers on every program run */ 
  
    /* Use current time as seed for random generator */ 
    srand(time(NULL)); 
  
    for(int i = 0; i<6; i++) 
        arrRandomNum[i]= rand()%50;

    printf("\n");

    int arr[49], i , j;
    /*init array with numbers from 1 tp 49*/
    for (i=0; i<49; i++)
    {
        arr[i]=i+1;
    }
    /*compare random numbers with array*/
    for(i=0; i<49; i++)
        {
            for(j=0; j<6; j++)
            {
                if (arrRandomNum[j]==arr[i])
                {
                    arr[i]=0;
                }
                
            }
        }

    /*convert array to -\+ symbols*/
     for(i=0; i<49; i++)
        {
            if (arr[i]!=0)
            {
                arr[i]='-';
            }
            else
            {
                arr[i]='+';
            }
            
        }
    
/*print matrix*/
    printf("\t");
    int rows = 5, cols = 9, count=0, xRow, yCol=0;
    /*print first line- row (1-10)*/
    for(xRow=1; xRow<=10; xRow++)
    {
        printf("%d\t", xRow);   
    }
    printf("\n");   

    for(i = 0; i < rows; ++i)
    {   
        
        printf("%d\t", yCol/10);/*print col number (0-4)*/

        for(j = 0; j <= cols ; ++j) 
        {
            printf("%c\t",arr[count]);
            count++;
            yCol++;
        }
        printf("\n");
    }

    // int x, y;
    // for(x=1; x<=10; x++)
    // {
    //     printf("%d\t ", x);   
    // }
    // printf("\n");

    
    // int rows = 5, cols = 9, count=0;
    // for(i = 0; i < rows; ++i)
    // {
    //     printf("%d\t", j);
    //     for(j = 0; j <= cols ; j++) 
    //     {
            
    //         printf("%d\t",arr[count]);
    //         count++;
    //     }
    //     printf("\n");
    // }

   
}