#include<iostream>
#include<fstream>
using namespace std;

int main()
{//ofsteam��д�룬ifstream�Ƕ�ȡ 
	ifstream inFile;
	if(!inFile.is_open())
		cout<<"��ʱ��δ��"<<endl;
	inFile.open("test");
	if(inFile.is_open())
		cout<<"��ʱ�Ѿ���"<<endl;
	
	if(!inFile.is_open())//�Ƿ��Ѵ� 
		exit(EXIT_FAILURE);
	
	
	char str[100];
	inFile>>str;
	cout<<str;
	return 0;
}
