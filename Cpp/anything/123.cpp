#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<long long>a(n);
    for(auto&x:a)
        cin>>x;
    long long ans=0;
    //0 1 2 3
    //0 1 3 6
    vector<long long>he(100005);
    for(int i=0;i<he.size();i++)
    {
        if(i==0)
            he[0]=0;
        else
            he[i]=he[i-1]+i;
        cout<<i<<' '<<he[i]<<'\n';
        if(he[i]>1e16)
        	break;
    }
    for(auto&x:a)
    {
        int l=0,r=100000;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(he[mid]<x)
                l=mid;
            else
                r=mid-1;
        }
        ans+=he[l];
    }
    cout<<ans;
    return 0;
}
