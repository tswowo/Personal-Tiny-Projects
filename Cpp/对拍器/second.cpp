#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
	cin>>n>>k;
	vector<int>a(n);
    for(auto&x:a)
        cin>>x;
    int ans=upper_bound(a.begin(),a.end(),k)-a.begin();
    cout<<ans;
    return 0;
}
