#include<iostream>
#include<cstring>
using namespace std;

//ģ�涨�壺�Թؼ���template��ʼ�����һ��ģ������б�����һ�����ŷָ���һ������ģ��������б�
//һ����ģ����� 
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

//һ������ģ�����
//1����value��N�� 
template<int N>
int multiplyByN(int value)
{
	return value*N;
}
//2�����ʾ��������ĳ���
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
	string c=gouzao("����");
	cout<<c<<endl;
	cout<<compare("h1","hellow");
	/*ʵ���ϱ�����������ʵ�ֵ�:
		int compare(const char (&p1)[3],const char (&p2)[7])
	*/ 
    return 0;
}
