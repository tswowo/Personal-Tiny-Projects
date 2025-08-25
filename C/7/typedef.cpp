#include<stdio.h>

typedef int num;

typedef struct{
	int num;
	char name[10];
}st;

int main()
{
	num a;
	a=1;
	printf("%d\n",a);
	
	st b={1,"TOM"};
	printf("%d\n%s\n",b.num,b.name);
	printf("%p\n%p",b,&b.num);
	return 0; 
}
