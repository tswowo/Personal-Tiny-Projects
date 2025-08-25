#include<bits/stdc++.h>

void quick_sort(int*a,int l,int r)
{
	if(l>=r)
		return;
	int i=l-1,j=r+1,x=a[l+r>>1];
	while(i<j)
	{
		do i++; while(a[i]<x);
		do j--; while(a[j]>x);
		if(i<j)
			std::swap(a[i],a[j]);
	}
	quick_sort(a,l,j);
	quick_sort(a,j+1,r);
}

int main()
{
	int n;std::cin>>n;
	int *a=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		std::cin>>a[i];
	quick_sort(a,0,n-1);
	for(int i=0;i<n;i++)
		std::cout<<a[i]<<' ';
	return 0;
}
