#include<iostream>
using namespace std;

class human
{
	private://�������ڲ����� 
		string name;
	protected://�����ڲ�������ɷ��� 
		int age;
		bool sex;
	public://������Կɷ��� 
		human(string name1="None",int age1=-1,bool sex1=false):name(name1),age(age1),sex(sex1){}
};

class student:public human
{
	private:
		int grade;
	public:
		student(int age1=-1,bool sex1=false,int grade1=-2)
		{
			age=age1;
			sex=sex1;
			grade=grade1;
		}
		void printStudentInformation()
		{
			cout<<"age:"<<age<<" sex:"<<sex<<" grade:"<<grade<<endl;
		}
};

int main()
{
	student li(19,23,8);
	li.printStudentInformation();
	return 0;
}
