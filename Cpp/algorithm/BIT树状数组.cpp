#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	auto lowbit=[&](int x)->int{//�õ��õ������������͵�����Ĵ�С
		return x&-x;//����������ʣ������ҵ��õ��ǰһ���ͺ�һ������͵�λ��
	};
	auto query=[&](int x)->int{//�Ӻ���ǰ�� 
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
	auto update=[&](int pos,int val)->void{//��ǰ������� 
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
