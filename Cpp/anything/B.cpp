#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,s;cin>>n>>s;
        long long cnt=0,sum=0;
        for(int i=0;i<n;i++)
        {
            int r,c;cin>>r>>c;
            if(r==1)
                cnt++;
            sum+=c;
        }
        if((n%2==1&&cnt>n/2)||(n%2==0&&cnt>=n/2))
            cout<<"1 ";
        else
            cout<<"0 ";
        if(sum>=s+50)
            cout<<"1\n";
        else
            cout<<"0\n";
    }
    return 0;
}
