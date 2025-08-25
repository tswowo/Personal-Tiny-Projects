#include<iostream>
#include<string>
using namespace std;
//���һ��̳� 
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

class doctor:public human//�������public->public protected->protected 
{
	private:
		int Bio_ability;
	public:
		void work()
		{
			cout<<"ҽ��ˮƽ:"<<Bio_ability<<" ������"<<endl;
		}
};

class police:public human//�������public->protected protected->protected
{
	private:
		int Cat_ability;
	public:
		void catching()
		{
			cout<<"׷��ˮƽ:"<<Cat_ability<<" ץ���˷���"<<endl;
		}
};

class teacher:public human//�������public->private protect->protected 
{
	protected:
		int teach_ability;
	public:
		void teaching()
		{
			cout<<"��ѧˮƽ:"<<teach_ability<<" �Ͽ�����"<<endl;
		}
};
//�������ּ̳з�ʽ�������private�����ᱻ�̳� 

int main()
{
	teacher wang;
	wang.printHuman();
	wang.teaching();
	return 0;
}
