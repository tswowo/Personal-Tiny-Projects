#include<iostream>
#include<stack>
#include<utility>
using namespace std;
int main()
{
    stack<pair<int,int>> stk;
    stk.push(pair<int,int>(10,11));
    stk.push(make_pair(12,13));
    stk.push(make_pair(13,14));
    stk.push(pair<int,int>(14,15));
    stk.push(pair<int,int>(15,99));
    while(!stk.empty())
    {
    	auto x=stk.top();
    	cout<<x.first<<' '<<x.second<<" Stack_size:"<<stk.size()<<endl;
    	stk.pop();
	}
	return 0;
}
