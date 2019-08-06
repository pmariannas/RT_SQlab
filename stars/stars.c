    #include <stdio.h>
void func1(void);
void func2(void);
void func3(void);
int main(void){
	func1();
	func2();
	func3();
	return 0;
}

void func1(void)
{
	int N,i,j; 
    	printf("Please give integers for func1:\n");
	scanf("%d", &N);
	
	for( i = 1; i <= N; i++)
	{
		for(j = 1; j <= i;j++)
		{
		    printf("*");
		}
		printf("\n");
	}

}
void func2()
{
	int N = 0;
	int i,j; 
    	printf("Please give integers for func2:\n");
	scanf("%d", &N);
	for( i = 1; i <= N; i++)
	{
		for(j = 1; j <= i;j++)
		{
		    printf("*");
		}
		printf("\n");
	}
	for( i = N; i >= 1; i--)
	{
		for(j = 1; j <= i;j++)
		{
		    printf("*");
		}
		printf("\n");
	}


}
void func3()
{
	int rows,i,j,space = 0; 
    	printf("Please give integers, number of rows, for func3:\n");
	scanf("%d", &rows);     
	for( i = 1; i <= rows; i++)
	{
		for(space=1; space<=(rows-i); space++){
			printf(" ");
		}

		for(j = 0; j != ((i*2)-1);j++)
		{
		    printf("*");

		}

		printf("\n");

	}
	

}
