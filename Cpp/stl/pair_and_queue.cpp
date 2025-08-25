#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int main()
{
	
	queue<tuple<int,int>>q;
	q.push(tuple<int,int>(1,2));
	auto tmp=q.front();
	q.pop();
	auto x=get<0>(tmp),y=get<1>(tmp);
	cout<<x<<" "<<y<<endl;
	return 0;
}
