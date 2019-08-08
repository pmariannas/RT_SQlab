#include <stdio.h>
#include <stdlib.h>
#include<time.h> 


void sortArrayAscending(int* arr , int sizeArr );
void sortArray01();
int occurMost();
void lotto();

int main()
{
    int sizeArr;
    int sizeArr5;

    int arr[5] = { 3,1,2,5,4}; /*array question 1*/
    int arr5[11] = {3, 6 ,8 ,3 ,9 ,12, 45, 9 ,12 ,56, 12}; /*array question 5*/
    sizeArr = 5;/*len of array from question 1*/
    sizeArr5 = 11; /*len of array from question 5*/
    
    printf("1) sortArrayAscending:\n ");
    sortArrayAscending(arr, sizeArr);
    printf("\n");
    printf("2) sortArray01:\n ");
    sortArray01();
    printf("\n");
    printf("5) occurMost:\n ");
   
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

        /*print the array*/
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
    int arr[49], i , j;
    int rows , cols, count, xRow, yCol;

    /*This program will create different sequence of */  
    /*random numbers on every program run */ 
  
    /* Use current time as seed for random generator */ 
    srand(time(NULL)); 
    for(i = 0; i<6; i++) 
    {
        arrRandomNum[i]= rand()%50;
    }
        
    printf("\n");

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
    
	/*print array*/
    printf("\t");
    rows = 5;
    cols = 9;
    count = 0;
    yCol = 0;
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

    
   
}
