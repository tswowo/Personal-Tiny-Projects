#include<iostream> cout
#include<fstream>  

using namespace std;

int main()
{
	//Èçcout°ãÊ¹ÓÃfout 
	ofstream outFile;
	char str[50];
	cin>>str;
	outFile.open("test");
	outFile<<str;
	outFile.close();
	return 0;
}
