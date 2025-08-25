#include<stdio.h>
int main(){
	int a=3;
	int *b=&a;
	int *c=b;
	printf("b=%d\n",b);
	printf("b=%p\n",b);
	printf("*b=%d\n",*b);
	printf("*b=%p\n",*b);
	
	printf("c=%d\n",c);
	printf("c=%p\n",c);
	printf("*c=%d\n",*c);
	printf("*c=%p\n",*c);
}
/*
指针变量是一种特殊的变量。 
定义它时要使用*，
而调用它时，
如果你想修改它指向的变量需要加*，
如果你想修改指针不需要加*
*/
