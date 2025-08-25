#include<iostream>

signed main()
{
	void*pv;
	int i=23;
	char c='a';
	std::string s="114514";
	pv=&i;
	std::cout<<*(int*)pv<<std::endl;
	pv=&c;
	std::cout<<*(char*)pv<<std::endl;
	pv=&s;
	std::cout<<*(std::string*)pv<<std::endl;
}
