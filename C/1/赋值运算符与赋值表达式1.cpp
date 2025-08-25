#include<stdio.h>
main(){
	int a,b,c;
	a=b=c=16;//先给c赋值，再给b赋值，再给a赋值 
	printf("%d\n",a);
	printf("%d\n",b);
	printf("%d\n",c);
	//算术运算符和关系运算符是左结合性，赋值运算符是右结合性 
	//类似于f=3+2  左侧为变量，右侧为常量或其他有确切结果的表达式 
}
