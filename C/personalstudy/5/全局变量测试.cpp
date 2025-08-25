#include<stdio.h>
int x=1,y=2;
int z=x+y;
void f1()//变量名重复时，函数优先使用函数内部定义的变量，此时修改内部变量，不影响外部变量的内容 
{
	int x=0;
	printf("f1 x=%d y=%d z=%d\n",x,y,z);
	x+=1;
	printf("x=%d y=%d z=%d\n",x,y,z);
	z=0;
}
void f2()
{
	printf("f2 x=%d y=%d z=%d\n",x,y,z);
	x+=1;
	printf("x=%d y=%d z=%d\n",x,y,z);
	z=0;
}
int main()
{
	f1();
	f2();
	printf("main x=%d y=%d z=%d\n",x,y,z);
	x+=1;
	printf("x=%d y=%d z=%d\n",x,y,z);
}
