#include<iostream>

void worry(int a)
{
	printf("in worry(a): &a:%p\n",&a);//�¿���һ���ڴ�ռ� 
	a=-1;//�⵱Ȼֻ��ı�worry�����ڵ�a 
}

void f(int &a)
{	
	printf("in f(a): &a:%p\n",&a);//���� 
	a=0;
}

void g(int *a)
{
	printf("in g(a): &a:%p\n",a);
	*a=1;
}

int main()
{
	int a=114514,c=9;
	int &b=a;
//	&b=c;�����ǲ����Եģ�ֻ�����ڶ���ʱ����Ϊaȡ����Ϊb
//	b=c;�����Ὣb��a�ı�����Ϊc�ı��������ǻ��a��b��ֵ��Ϊc 
//	std::cout<<a<<std::endl;
//	std::cout<<b<<std::endl;
//	b+=12;
//	std::cout<<a<<std::endl;
	printf("in main: &a:%p &b:%p\n",&a,&b);
	f(b);
	std::cout<<"and a was changed to:"<<a<<std::endl;
	g(&a);
	std::cout<<"and a was changed to:"<<a<<std::endl;
	worry(a);
	return 0;
}
