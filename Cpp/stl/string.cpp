#include<iostream>
#include<string>
using namespace std;

int main()
{
	//1.���캯��
	string s1;//�մ�
	string s2(s1);//s1����
	string s3=s2;//s1����
	char str1[]="value";
	string s4("value");//"value"�ĸ���//C����ַ������� 
	string s5(5,'v');//string s(n,'value')n��value��string 
	char str2[]={'v','a','l','u','e'};
	string s6(str2,5);//ʹ���ַ�����ͳ��ȹ��� 
	
	s6.clear();//�������� 
	
	//2.��������� 
	s1="hello";//��ֵ����� 
	s2=s5;
	cout<<s1<<endl<<s2<<endl;
	
	s3=s1+s2;//�ӷ�������������ַ��� 
	cout<<s3<<endl;
	
	//�Ƚ����������>,<,<=,>=,== ASCII�ֵ�˳��
	//s1==s2 s1>s2 s1<s2 s1>=s2 s1<=s2
	
	cout<<s3[5]<<endl;//�±������ �����±�
	
	s3+=s1;// ���ϸ�ֵ�����
	cout<<s3<<endl; 
	
	//3.��Ա���� 
	string s="123 456";
	cout<<s<<endl<<s[0]<<" ����capacity:"<<s.capacity()<<" length/size:"<<s.length()<<endl;
	s.erase(s.begin());//ɾ��������λ�õ����� 
	s.append("1");//���ַ���β����ַ��� 
	cout<<s<<endl<<s[0]<<" ����capacity:"<<s.capacity()<<" length/size:"<<s.size()<<endl;
	s.assign(s1);//�����ַ�������ԭ�ַ��� s.assign(string) s.assign("str") 
	cout<<s<<endl;
	cout<<s.at(1)<<endl;//����ָ��λ�õ��ַ�
	cout<<s.back()<<endl;//���������ַ�
	cout<<s.front()<<endl;//���ص�һ���ַ�
	s="123456";
	//�������ַ���λ��  
	cout<<"234ins1: "<<s.find("234")<<endl;
	cout<<"124ins1: "<<s.find("124")<<endl;
	cout<<"78ins1: "<<s.find("78")<<endl;
	//�ȵ�
	s="123456789";
	cout<<s<<endl;
	s.replace(1,0,"123456789");//��1λ�ò���str������0���ַ� 
	cout<<s<<endl;
	s="123456789";
	//����
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
