#include<iostream>
#include<cstring>
using namespace std;

//模版定义：以关键字template开始，后跟一个模板参数列表，这是一个逗号分隔的一个或多个模板参数的列表
//一类型模板参数 
template<typename T1,typename T2>
void compare1(T1& a,T2& b)
{
	cout<<(a>b?a:b)<<endl;
}

template<typename T>
T gouzao(T value)
{
	return value;
}

//一非类型模板参数
//1返回value的N倍 
template<int N>
int multiplyByN(int value)
{
	return value*N;
}
//2例如表示两个数组的长度
template<unsigned int N,unsigned int M>
int compare(const char(&p1)[N],const char(&p2)[M])
{
	return strcmp(p1,p2);
}
 
int main()
{
//	char a='1',b='2';
//	compare1(a,a);
//	compare1(a,b);
	int a=gouzao(1);
	cout<<a<<endl;
	double b=gouzao(1.14);
	cout<<b<<endl;
	string c=gouzao("我是");
	cout<<c<<endl;
	cout<<compare("h1","hellow");
	/*实际上编译器是这样实现的:
		int compare(const char (&p1)[3],const char (&p2)[7])
	*/ 
    return 0;
}
