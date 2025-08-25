#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	auto lowbit=[&](int x)->int{//得到该点所储存的区间和的区间的大小
		return x&-x;//利用这个性质，可以找到该点的前一个和后一个区间和的位置
	};
	auto query=[&](int x)->int{//从后往前加 
		if(x<1)
			return 0;
		int ans=0;
		while(x>0)
		{
			ans+=a[x];
			x-=lowbit(x);
		}
		return ans;
	};
	auto update=[&](int pos,int val)->void{//从前往后更新 
		while(pos<=n)
		{
			a[pos]+=val;
			pos+=lowbit(pos);
		}
	};
	for(int i=1;i<=n;i++)
	{
		int tmp;cin>>tmp;
		update(i,tmp);
	}
	while(m--)
	{
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1)
			update(x,y);
		else if(op==2)
			cout<<query(y)-query(x-1)<<'\n';
	}
    return 0;
}
