#include<bits/stdc++.h> 

using namespace std;

long long lowbit(long long x)
{
    return x & -x;
}

int main( )
{
    int n,q;cin>>n>>q;
    vector<long long>a(n);
    for(auto&x:a)
        cin>>x;
    while(q--)
    {
        int op;cin>>op;
        if(op==1)
            for(auto&x:a)
                x+=lowbit(x);
        else
        {
            long long ans=0LL;
            for(auto&x:a)
                ans=(ans+x)%998244353;
            cout<<ans<<'\n';
        }
    }
    return 0;
}
