#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,m;
    cin>>n>>m;
    vector<vector<int>>f(n+1,vector<int>(21));
    vector<int>lg(n+1);
    for(int i=2;i<=n;i++)
        lg[i]=lg[i/2]+1;
    for(int i=1;i<=n;i++)
        cin>>f[i][0];
    for(int j=1;j<=lg[n];j++)
        for(int i=1;i<=n;i++)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        int len=lg[r-l+1];
        cout<<max(f[l][len],f[r-(1<<len)+1][len])<<'\n';
    }
    return 0;
}
