#include<iostream>
#include<string>
using namespace std;
//类的一般继承 
class human
{
	private:
		
	protected:
		string name;
		int age;
		bool sex;
	public:
		human(string a="None",int b=-1,bool c=0)
		{
			name=a;
			age=b;
			sex=c;
		}
		human(human &other)
		{
			name=other.name;
			age=other.age;
			sex=other.sex;
		}
		human &operator=(const human &other)
		{
			if(this!=&other)
			{
				name=other.name;
				age=other.age;
				sex=other.sex;
			}
			return *this;
		}
		void printHuman()
		{
			cout<<"name:"<<name<<" age:"<<age<<" sex:"<<sex<<endl;
		}
};

class doctor:public human//将父类的public->public protected->protected 
{
	private:
		int Bio_ability;
	public:
		void work()
		{
			cout<<"医术水平:"<<Bio_ability<<" 救人了"<<endl;
		}
};

class police:public human//将父类的public->protected protected->protected
{
	private:
		int Cat_ability;
	public:
		void catching()
		{
			cout<<"追捕水平:"<<Cat_ability<<" 抓捕了犯人"<<endl;
		}
};

class teacher:public human//将父类的public->private protect->protected 
{
	protected:
		int teach_ability;
	public:
		void teaching()
		{
			cout<<"教学水平:"<<teach_ability<<" 上课了啦"<<endl;
		}
};
//不管哪种继承方式，父类的private都不会被继承 

int main()
{
	teacher wang;
	wang.printHuman();
	wang.teaching();
	return 0;
}
