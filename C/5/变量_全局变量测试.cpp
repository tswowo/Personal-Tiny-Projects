#include<stdio.h>
/*2.全局变量

 在函数之外定义的变量称为全局变量，也称为外部变量，其作用域为从定义变量的位置开始到本源文件结束。

说明：

 　（1）因为函数只能返回一个返回值，因此可以通过使用全局变量来实现一个函数改变多个值后，还能被其他函数调用。

　　（2）全局变量在程序执行整个过程中都占用存储单元，使用太多全局变量所以占用空间比较大。

　　（3）局部变量会屏蔽同名的全局变量，即局部变量优先。*/
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


#include<stdio.h>
int x,y;
void swap()
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
int main()
{
	x=1;y=2;
	printf("x=%d y=%d\n",x,y);
	swap();
	printf("x=%d y=%d\n",x,y);
}



#include<stdio.h>
int s1,s2,s3;
/*4.静态存储方式

 程序运行期间由系统分配固定的存储空间的方式。

说明：

 （1）在程序执行整个过程中都占用存储单元，如果静态变量在定义时不初始化，其值都为0或“\0”。*/
void count(int a,int b,int c)
{
	s1=a*b;s2=a*c;s3=b*c;
}
int main()
{
	printf("%d %d %d",s1,s2,s3);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	count(a,b,c);
	printf("%d %d %d",s1,s2,s3);
	return 0;
}
