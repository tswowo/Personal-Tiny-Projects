#include <iostream>
using namespace std;

	
typedef int(*MyFuncTypePtr)(int,int);
typedef int(MyFuncType)(int,int);

int multiply(int a,int b)
{
	return a*b;
}

int add(int a,int b)
{
	return a+b;
}

int acc(int a,int b,MyFuncTypePtr rules)
{
	return rules(a,b);
}

int main() {
    //函数指针的声明
	//返回类型(*函数指针名称)(参数列表);
	cout<<hex<<multiply<<endl;
	//double(*ptr)(int a,int b);对函数指针，传参叫什么并没有意义，一般省略为： 
	int (*ptr)(int,int)=multiply;
	cout<<multiply(2,3)<<endl;
	cout<<ptr(2,3)<<endl;//可以直接使用 
	cout<<(*ptr)(2,3)<<endl;//亦可以使用解引用运算符+函数指针 
	
	cout<<dec<<endl;
	
	ptr=&add;
	cout<<add(3,4)<<endl;
	cout<<ptr(3,4)<<endl;
	cout<<(*ptr)(3,4)<<endl;
	
	cout<<endl;
	
	//typedef int(*MyFuncTypePtr)(int a,int b);
	//typedef int(*MyFuncTypePtr)(int,int);
	MyFuncTypePtr ptr1=multiply;
	cout<<ptr1(1,2)<<endl;
	ptr1=&add;
	cout<<ptr1(1,2)<<endl;
	
	cout<<endl;
	
	//typedef int(MyFuncType)(int,int);
	MyFuncType *ptr2=multiply;
	cout<<ptr2(3,4)<<endl;
	ptr2=&add;
	cout<<ptr2(3,4)<<endl;
	
	cout<<endl;
	
	auto ptr3=multiply;
	cout<<ptr3(5,6)<<endl;
	ptr3=&add;
	cout<<ptr3(5,6)<<endl;
	
	cout<<endl;
	//auto只能用于定义单个函数指针，不能定义函数指针数组:
	//auto ptrs[]={multiply,add};这样会报错
	MyFuncTypePtr ptrs[]={multiply,add};
	for(int i=0;i<2;i++)
		cout<<ptrs[i](3,4)<<endl;
		
	cout<<endl;
	
	//函数传入函数指针：
	
	cout<<acc(2,3,ptrs[0])<<endl;
	cout<<acc(2,3,ptrs[1])<<endl;
//	typedef int My(int a,int b);
//	
//	int add(int a,int b)
//	{
//		return a+b;
//	}
//	
//	int main()
//	{
//		My *a=add;
//		int (*b)(int,int)=add;
//		return 0;
//	}
}
	 
    return 0;
}
