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

//1ȷ����������ʹ��� 
void func1(student<string,int>&p)
{
	p.showme();
}

//2����ģ�廯
template<typename T1,typename T2>
void func2(student<T1,T2>&p)
{
	p.showme();
}

//3��ģ�廯
template<typename a>
void func3(a&p)
{
	p.func();
}

int main()
{
	student<string,int> ming("�ر�",1034);
	func3(ming);
}
