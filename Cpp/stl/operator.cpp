#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;
/*
返回类型 operator 运算符 (参数列表) {
    // 函数体
}
*/
class Myclass{
	private:
		int id;
		string name;
	public:
		Myclass(int id,string name):id(id),name(name){}
		Myclass(int id)
		{
			this->id=id;
		}
		Myclass(string name)
		{
			this->name=name;
		}
		bool operator<(const Myclass&b)//对象内的operator内隐含一个this指针 
		{
			if(this->id!=b.id)
				return this->id<b.id;
			return this->name<b.name;
		}
		friend ostream& operator<<(ostream&os,const Myclass&a)//friend声明的友元函数不隐含this指针。 
		{
			os<<a.id<<' '<<a.name<<endl;
			return os;
		}
		friend istream& operator>>(istream&is,Myclass&a);
		friend stringstream& operator<<(stringstream&s,const Myclass&a)
		{
			s<<a.id<<' '<<a.name<<endl;
			return s;
		}
		friend stringstream& operator>>(stringstream&s,Myclass&a)
		{
			s>>a.id>>a.name;
			return s;
		}
		void getId()
		{
			cout<<this->id<<endl;
		}
		void getName()
		{
			cout<<this->name<<endl;
		}
		void getVal()
		{
			cout<<this->id<<' '<<this->name<<endl;
		}
};

istream& operator>>(istream&is,Myclass&a)
{
	is>>a.id>>a.name;
	return is;
}

int main()
{
	int n;
	cin>>n;
	vector<Myclass>users;
	for(int i=0;i<n;i++)
	{
//		Myclass tmp;
//		cin>>tmp;
		users.push_back(Myclass(n-i,"0"+to_string(n-i)));
	}
	for(int i=0;i<n;i++)
		users[i].getVal();
	sort(users.begin(),users.end());
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<users[i];
	return 0;
}
