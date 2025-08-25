#include<iostream>
using namespace std;

inline double circle(double r)
{
	double PI=3.14;
	return PI*r*r;
}

signed main()
{
	for(auto i=0;i<10;i++)
		cout<<"r:"<<i<<" circle:"<<circle(i)<<endl;
	return -1;
}
