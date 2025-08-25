#include<bits/stdc++.h>

using namespace std;

int n,blo;
int v[50010],belong[50010],lazy[50010];
vector<int> ve[250];

void reset(int idx)
{
	ve[idx].clear();
	for(int i=(idx-1)*blo+1;i<=min(idx*blo,n);i++)
		ve[idx].push_back(v[i]);
	sort(ve[idx].begin(),ve[idx].end());
}

void add(int l,int r,int c)
{
	for(int i=l;i<=min(r,belong[l]*blo);i++)
		v[i]+=c;
	reset(belong[l]);
	if(belong[l]!=belong[r])
	{
		for(int i=(belong[r]-1)*blo+1;i<=r;i++)
			v[i]+=c;
		reset(belong[r]);
	}
	for(int i=belong[l]+1;i<=belong[r]-1;i++)
		lazy[i]+=c;
}

int query(int l,int r,int c)
{
	int ans=0;
	for(int i=l;i<=min(r,belong[l]*blo);i++)
		if(v[i]+lazy[belong[l]]<c)
			ans++;
	if(belong[l]!=belong[r])
		for(int i=(belong[r]-1)*blo+1;i<=r;i++)
			if(v[i]+lazy[belong[r]]<c)
				ans++;
	for(int i=belong[l]+1;i<=belong[r]-1;i++)
	{
		int x=c-lazy[i];//需要的值减去懒标记的大小就是实际上需要的原数组内元素的大小
		ans+=lower_bound(ve[i].begin(),ve[i].end(),x)-ve[i].begin();//二分查找到第一个符合要求的值就好了 
	}
	return ans;
}

int main()
{
	cin>>n;
	blo=sqrt(n);
	for(int i=1;i<=n;i++)
		cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        belong[i]=(i-1)/blo+1;
        ve[belong[i]].push_back(v[i]);
    }
    for(int i=1;i<=belong[n];i++)
    	sort(ve[i].begin(),ve[i].end());
	for(int q=1;q<=n;q++)
	{
		int op,l,r,c;
		cin>>op>>l>>r>>c;
		if(op==0)
			add(l,r,c);
		else
			cout<<query(l,r,c*c)<<'\n';
	}
	return 0;
}
