#include<iostream>
using namespace std;

class human
{
	private://仅该类内部访问 
		string name;
	protected://该类内部和子类可访问 
		int age;
		bool sex;
	public://类内外皆可访问 
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
