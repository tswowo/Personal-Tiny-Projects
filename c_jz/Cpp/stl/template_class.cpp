#include<iostream>
#include<string>
using namespace std;

template<typename T1,typename T2>
class student
{
	public:
		student(T1 name,T2 score)
		{
			this->name=name;
			this->score=score;
		}
		void showme()
		{
			cout<<name<<' '<<score<<endl;
		}
		void func()
		{
			cout<<"begin!!"<<endl;
		}
	private:
		T1 name;
		T2 score;
};

template<typename T1,typename T2>
class teacher
{
	public:
		teacher(T1 name,T2 score)
		{
			this->name=name;
			this->score=score;
		}
		void showme()
		{
			cout<<name<<' '<<score<<endl;
		}
		void func()
		{
			cout<<"begin!!"<<endl;
		}
	private:
		T1 name;
		T2 score;
};

//1确定具体的类型传入 
void func1(student<string,int>&p)
{
	p.showme();
}

//2参数模板化
template<typename T1,typename T2>
void func2(student<T1,T2>&p)
{
	p.showme();
}

//3类模板化
template<typename a>
void func3(a&p)
{
	p.func();
}

int main()
{
	student<string,int> ming("关闭",1034);
	func3(ming);
}
