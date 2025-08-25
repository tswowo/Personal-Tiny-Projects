#include<stdio.h>
//默认定义的是局部变量(自动变量auto register) 
//全局变量（静态变量extern） 
void f(); /*函数说明*/
int main()
{
	int i;

	for(i=1;i<=5;i++)
		f(); /*函数调用*/		
}
void f() /*函数定义*/
{
	static int k=0;
	k++;
	printf("%d\n",k);
}

