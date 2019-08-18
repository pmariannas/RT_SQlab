#include <stdio.h>
int checkPalindrome();
int checkAscending();
int perfectNumber();
int toReverse();
int checkPrime();

int main(void){
    int out;
	checkPalindrome();
	checkAscending();
	out = perfectNumber();
    printf("%d\n",out);
    toReverse();
    checkPrime();
	return 0;
}

int checkPalindrome(){
    int num, reversedNumber = 0, lastdigit, numbertocompare;
    printf("Enter an number to check palindrome: \n");
    scanf("%d", &num);
    numbertocompare= num;
    while( num!=0 )
    {
        lastdigit = num%10;
        reversedNumber = reversedNumber*10 + lastdigit;
        num = num/10;
    }
    if (numbertocompare==reversedNumber){
        return printf("this is palindrome: %d\n", numbertocompare);
    }
    else 
    {
        return printf("this is not palindrome: %d\n", numbertocompare);
    }
    
    
}

int checkAscending(){
    int num, prevlast, lastdigit;
    printf("checkAscending-Enter an number to check: ");
    scanf("%d", &num);
    while( num!=0 )
    {
        lastdigit = num%10; /*last digit*/
        num = num/10;
        prevlast = num%10; /*prev lasr digit*/
        if (lastdigit<prevlast){
            return 0 ;
        }
    }

    return 1;
}

int perfectNumber(){
    int out, in, i, sum = 0;
    printf("Enter an number to check if is it perfect number: ");
    scanf("%d", &in);


    for (i = 1; i < in; i++) {
        if ((in % i) == 0) {
        sum += i;
        }
    }
    return sum == in;
    }


int toReverse(){
    int num, reversedNumber = 0, lastdigit;
    printf("Enter an number to reverse: ");
    scanf("%d", &num);
    while( num!=0 )
    {
        lastdigit = num%10;
        reversedNumber = reversedNumber*10 + lastdigit;
        num = num/10;
    }
    
        return printf("reversed number: %d\n", reversedNumber);
    
}

int checkPrime(){
    int i,num;
   
    printf("Enter an number to check if prime: \n");
    scanf("%d", &num);
    if (num==1||num<=0){
        printf ("the number you put is not positive integer or you put 1");
        return 0;
    }
    for (i=2; i<num/2; i++){
        if (num%i==0){
            printf("this is not prime number %d", num);
            return 0;
        }
    }
    printf ("this is prime number: %d", num);
    return 1;
}
