#include<iostream>
#include<fstream>
using namespace std;

int main()
{//ofsteam是写入，ifstream是读取 
	ifstream inFile;
	if(!inFile.is_open())
		cout<<"此时还未打开"<<endl;
	inFile.open("test");
	if(inFile.is_open())
		cout<<"此时已经打开"<<endl;
	
	if(!inFile.is_open())//是否已打开 
		exit(EXIT_FAILURE);
	
	
	char str[100];
	inFile>>str;
	cout<<str;
	return 0;
}
