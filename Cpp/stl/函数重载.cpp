#include<iostream>
using namespace std;
//��ͬһ�������ڿ��Զ�����������ͬ�������б�ͬ�ĺ�����
//�����������ݵ��ú���ʱ����Ĳ������ͺ�������������������ĸ�������

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
