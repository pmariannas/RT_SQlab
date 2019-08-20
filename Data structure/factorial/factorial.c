#include <stdio.h>

int factorialFunc(unsigned long N);

int main()
{
    int N = 11;
    int result = 1;
    result = N*factorialFunc((N-1));
    printf("%d \n", result);
    return 0;
}

int factorialFunc(unsigned long N)
{
    if(N==1)
    {
        return 1;
    }
    else
    {
        return (N*factorialFunc(N-1));

    }
    

}
