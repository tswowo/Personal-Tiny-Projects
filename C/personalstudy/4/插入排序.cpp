#include<stdio.h>
void print(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int end,temp;
	for(int i=0;i<n-1;i++)
	{
		end=i;
		temp=a[end+1];
		while(end>=0)
		{
			if(temp<a[end])
			{
				a[end+1]=a[end];
				end--;
			}
			else
				break;
		}
		a[end+1]=temp;
	}
	print(a,n);
	return 0;
}
