#include<stdio.h>
//结构体的定义 
struct people
{
	char *name;
	int age;
	int num;
	char *major;
};
int main()
{
	//结构体普通初始化:
	struct people one={"Bob",18,114,"A"};
	
	//指定成员初始化:
	struct people two;
	two.name="Alice";
	two.age=17;
	two.num=514;
	two.major="B";
	
	//测试一下 
	printf("%s\n",one.name);
	printf("%d\n",one.age);
	printf("%d\n",one.num);
	printf("%s\n",one.major);
	printf("%s\n",two.name);
	printf("%d\n",two.age);
	printf("%d\n",two.num);
	printf("%s\n",two.major);
}
