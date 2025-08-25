#include<bits/stdc++.h>

void merge_sort(int*a,int l,int r)
{
	//递归终止
	if(l>=r)
		return;
	//子问题分类讨论
	int mid=l+r>>1;
	merge_sort(a,l,mid);
	merge_sort(a,mid+1,r);
	//合并子区间
	int i=l,j=mid+1;
	int k=0,tmp[r-l+1];
	while(i<=mid&&j<=r)
	{
		if(a[i]<a[j])
			tmp[k++]=a[i++];
		else
			tmp[k++]=a[j++];
	}
	while(i<=mid)
		tmp[k++]=a[i++];
	while(j<=r)
		tmp[k++]=a[j++];
	for(int p=0;p<r-l+1;p++)
		a[l+p]=tmp[p];
}

int main()
{
	int n;std::cin>>n;
	int *a=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		std::cin>>a[i];
	merge_sort(a,0,n-1);
	for(int i=0;i<n;i++)
		std::cout<<a[i]<<' ';
	return 0;
}
