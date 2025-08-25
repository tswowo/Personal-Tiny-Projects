#include<iostream>
#include<string>
using namespace std;

int main()
{
	//1.构造函数
	string s1;//空串
	string s2(s1);//s1副本
	string s3=s2;//s1副本
	char str1[]="value";
	string s4("value");//"value"的副本//C风格字符串构建 
	string s5(5,'v');//string s(n,'value')n个value的string 
	char str2[]={'v','a','l','u','e'};
	string s6(str2,5);//使用字符数组和长度构建 
	
	s6.clear();//析构函数 
	
	//2.运算符重载 
	s1="hello";//赋值运算符 
	s2=s5;
	cout<<s1<<endl<<s2<<endl;
	
	s3=s1+s2;//加法运算符，连接字符串 
	cout<<s3<<endl;
	
	//比较运算符包括>,<,<=,>=,== ASCII字典顺序
	//s1==s2 s1>s2 s1<s2 s1>=s2 s1<=s2
	
	cout<<s3[5]<<endl;//下标运算符 访问下标
	
	s3+=s1;// 复合赋值运算符
	cout<<s3<<endl; 
	
	//3.成员函数 
	string s="123 456";
	cout<<s<<endl<<s[0]<<" 容量capacity:"<<s.capacity()<<" length/size:"<<s.length()<<endl;
	s.erase(s.begin());//删除迭代器位置的数据 
	s.append("1");//在字符串尾添加字符串 
	cout<<s<<endl<<s[0]<<" 容量capacity:"<<s.capacity()<<" length/size:"<<s.size()<<endl;
	s.assign(s1);//用新字符串代替原字符串 s.assign(string) s.assign("str") 
	cout<<s<<endl;
	cout<<s.at(1)<<endl;//返回指定位置的字符
	cout<<s.back()<<endl;//返回最后的字符
	cout<<s.front()<<endl;//返回第一个字符
	s="123456";
	//查找子字符串位置  
	cout<<"234ins1: "<<s.find("234")<<endl;
	cout<<"124ins1: "<<s.find("124")<<endl;
	cout<<"78ins1: "<<s.find("78")<<endl;
	//等等
	s="123456789";
	cout<<s<<endl;
	s.replace(1,0,"123456789");//在1位置插入str并代替0个字符 
	cout<<s<<endl;
	s="123456789";
	//遍历
	for(int i=0;i<s.size();i++)
		cout<<s[i]<<' ';
	cout<<endl;

	for(string::iterator x=s.begin();x!=s.end();x++)
		cout<<*x<<' ';
	cout<<endl;
	
	for(string::iterator x=s.end()-1;x!=s.begin()-1;x--)
		cout<<*x<<' ';
	cout<<endl;
	
	for(string::reverse_iterator x=s.rbegin();x!=s.rend();x++)
		cout<<*x<<' ';
	cout<<endl;
	
	for(auto x:s)
		cout<<x<<' ';
	cout<<endl;
	return 0;
}
