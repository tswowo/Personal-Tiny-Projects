#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(auto&i:a)
        cin>>i;
    int left=0,right=n;
    while(left<right)
    {
    	int mid=(right-left)/2+left;
    	if(a[mid]<=x)
    		left=mid+1;
    	else
    		right=mid;
	}
	cout<<left;
    return 0;
}
