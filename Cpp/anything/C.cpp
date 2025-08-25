#include<bits/stdc++.h>
using namespace std;
map<pair<long long,long long>,long long>grid;
long long n,m,s;
long long pp,sx,sy,ex,ey;
long long should=0;
long long xiancnt=0;
long long tozuo(long long x,long long y)
{
	return x*n+y;
}

int check(long long sx,long long sy,long long ex,long long ey)
{
//  sy sy+1
//sx
//ex
    int ans=0;
    if(abs(sx-ex)==1&&sy==ey)
    {
        if(grid.count({tozuo(sx,sy),tozuo(sx,sy+1)})!=0
		&&grid.count({tozuo(ex,sy),tozuo(ex,sy+1)})!=0
		&&grid.count({tozuo(sx,sy+1),tozuo(ex,sy+1)})!=0)
			ans++;
        if(grid.count({tozuo(sx,sy),tozuo(sx,sy-1)})!=0
		&&grid.count({tozuo(ex,sy),tozuo(ex,sy-1)})!=0
		&&grid.count({tozuo(sx,sy-1),tozuo(ex,sy-1)})!=0)
			ans++;
    }
//  sy ey
//sx
//sx+1
    if(abs(sy-ey)==1&&sx==ex)
    {
        if(grid.count({tozuo(sx,sy),tozuo(sx+1,sy)})!=0
		&&grid.count({tozuo(sx+1,sy),tozuo(sx+1,ey)})!=0
		&&grid.count({tozuo(sx,ey),tozuo(sx+1,ey)})!=0)
			ans++;
        if(grid.count({tozuo(sx,sy),tozuo(sx-1,sy)})!=0
		&&grid.count({tozuo(sx-1,sy),tozuo(sx-1,ey)})!=0
		&&grid.count({tozuo(sx,ey),tozuo(sx-1,ey)})!=0)
			ans++;
    }
    return ans;
}

bool hefa()
{
    if(sx<1||sx>n||ex<1||ex>n||sy<1||sy>m||ey<1||ey>m)
        return false;
    if(pp!=should)
        return false;
    if(abs(sx-ex)+abs(sy-ey)!=1)
        return false;
    if(grid.count({tozuo(sx,sy),tozuo(ex,ey)})!=0)
        return false;
    if(xiancnt==(n-1)*m+n*(m-1))
        return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    grid.clear();
    cin>>n>>m>>s;
    long long cnt[2];cnt[0]=0LL;cnt[1]=0LL;
    bool pro=true,defen=false;
    for(long long i=0;i<s;i++)
    {
        cin>>pp>>sx>>sy>>ex>>ey;
        if(!hefa())
        {
            if(!pro)
                cout<<' ';
            cout<<i+1;
            pro=false;
            continue;
        }
        xiancnt++;
        grid[{tozuo(sx,sy),tozuo(ex,ey)}]=1;
        grid[{tozuo(ex,ey),tozuo(sx,sy)}]=1;
        int ans=check(sx,sy,ex,ey);
        if(ans!=0)
            cnt[pp]+=ans;
        else
            should=1-should;
    }
    if(pro)
        cout<<"-1";
    if(cnt[0]>cnt[1])
        cout<<"\n0 "<<cnt[0];
    else
        cout<<"\n1 "<<cnt[1];
    return 0;
}
