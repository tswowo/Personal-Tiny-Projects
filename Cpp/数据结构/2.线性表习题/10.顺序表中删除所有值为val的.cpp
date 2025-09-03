#include<iostream>
using namespace std;

int* createADT(int n)
{
	int *val=new int[n];
	for(int i=0;i<n;i++)
		cin>>val[i];
	return val;
}

void deleteADT(int*ADT,int*n,int val)
{
	int left=0,right=0;
	while(right<*n)
	{
		if(ADT[right]!=val)
			ADT[left++]=ADT[right++];
		else
			right++;
	}
	*n=left;
}

void printADT(int*val,int n)
{
	for(int i=0;i<n;i++)
		cout<<val[i]<<' ';
	cout<<'\n';
}

int main()
{
	int n=10;
	int *a=createADT(n);
	printADT(a,n);
	deleteADT(a,&n,3);
	printADT(a,n);
	return 0;
}
