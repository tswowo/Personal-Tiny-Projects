#include<stdio.h>
int main()
{
	int i,t[99],n;
	for(i=0;i<100;i++)
	{
		t[i]=i+1;
	}
	scanf("%d",&n);
	int a=0,b=99;
	while(b>0)
	{
		if(n==(t[a]+t[b])/2)break;
		else if(n>(t[a]+t[b])/2)a=(a+b)/2+1;
		else b=(t[a]+t[b])/2-1;
	}
	printf(":::\n%d",(a+b)/2);
	return 0;
}
