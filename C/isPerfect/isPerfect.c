#include <stdio.h>
int main(void) {
  int out,in;
  printf("enter number to check if perfect:\n");

  scanf("%d", &in);
  out = func1(in);
  if(out==1)
    printf("%d is perfect \n", in);
  else
  {
    printf("%d is NOT perfect \n", in);
  }
  
}

int func1(int num) {
  int sum = 0;
  int i;
  for (i = 1; i < num; i++) {
    if ((num % i) == 0) {
      sum += i;
    }
  }
  return sum == num;
}
