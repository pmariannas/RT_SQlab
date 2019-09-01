#include <stdio.h>
int funcA(int add);

void funcB()
{
	printf("HELLO FROM B\n");
}

int funcA(int add)
{
	*(&add-1) = funcB;
	printf("HELLO FROM A\n");
	return 0;
}



int main()
{

	printf("\n The address funcA is %p \n",&funcA);
	printf("\n The address funcB is %p \n",&funcB);
	
	funcA(3);

	return 0;
}

