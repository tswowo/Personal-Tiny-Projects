#include<iostream>
using namespace std;
//在同一作用域内可以定义多个名称相同但参数列表不同的函数。
//编译器会依据调用函数时传入的参数类型和数量来决定具体调用哪个函数。

double add(double a,double b)
{
	return a+b;
}

int add(int a,int b)
{
	return a+b;
}

int main()
{
	cout<<add(1)<<endl;
	cout<<add(1.2,2.4)<<endl;
	cout<<add(1,2,3)<<endl;
}
