#include<bits/stdc++.h>
using namespace std;

int bound(vector<int>&ru)//找出入度为0点的下标 
{
	for(int i=1;i<ru.size();i++)
		if(ru[i]==0)
			return i;
	return -1;//仍有点，但没有入度为0的点了，说明存在环 
}

void clear(vector<int>&pp,vector<int>&ru)//清理 下标index 的影响 
{
	for(auto&x:pp)
		ru[x]--;
}

int main()
{
	int n;
	cin>>n;
	unordered_map<int,vector<int>>alls;
	vector<int>ru(n+1);
	for(int i=1;i<=n;i++)
	{
		int tmp;
		while(cin>>tmp&&tmp!=0)
		{
			ru[tmp]++;
			alls[i].push_back(tmp);
		}
	}
	vector<int>ans(n);
	for(int i=0;i<n;i++)
	{
		int index=bound(ru);
		ru[index]=-1;
		clear(alls[index],ru);
		ans[i]=index;
	}
	for(auto&x:ans)
		cout<<x<<' ';
	return 0;
}
