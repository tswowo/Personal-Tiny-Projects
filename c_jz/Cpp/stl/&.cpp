#include<iostream>

void worry(int a)
{
	printf("in worry(a): &a:%p\n",&a);//新开辟一个内存空间 
	a=-1;//这当然只会改变worry函数内的a 
}

void f(int &a)
{	
	printf("in f(a): &a:%p\n",&a);//仍是 
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
//	&b=c;这样是不可以的，只可以在定义时，即为a取别名为b
//	b=c;并不会将b从a的别名改为c的别名，而是会把a和b的值改为c 
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
