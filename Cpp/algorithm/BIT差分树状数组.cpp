#include<bits/stdc++.h>
using namespace std;

class BIT{
	private:
		vector<long long>a;
		long long n;
	public:
		long long lowbit(long long x)
		{
			return x&-x;
		}
		void update(long long pos,long long val)
		{
			for(;pos<=n;pos+=lowbit(pos))
				a[pos]+=val;
		}
		long long query(long long pos)
		{
			if(pos<=0)
				return 0;
			long long ans=0;
			for(;pos>0;pos-=lowbit(pos))
				ans+=a[pos];
			return ans;
		}
		void updateSegment(long long l,long long r,long long val)
		{
			update(l,val);
			update(r+1,-val);
		}
		BIT(long long n)
		{
			a.resize(n+1,0);
			this->n=n;
		}
};

int main()
{
	long long n,m;cin>>n>>m;
	BIT b(n);
	long long last=0;
	for(long long i=1;i<=n;i++)
	{
		long long tmp;cin>>tmp;
		b.update(i,tmp-last);
		last=tmp;
	}
	while(m--)
	{
		long long op;cin>>op;
		if(op==1)
		{
			long long x,y,k;cin>>x>>y>>k;
			b.updateSegment(x,y,k);
		}
		else
		{
			long long x;cin>>x;
			cout<<b.query(x)<<'\n';
		}
	}
    return 0;
}
