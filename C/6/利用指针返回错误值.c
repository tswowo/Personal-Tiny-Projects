#include<stdio.h>
int cal(int a,int b,int *c)//如果计算成功，返回1；如果不成功，返回0
{
	int ii=0;
	if(b!=0)
	{
		*c=a/b;
		ii=1;
	}
	return ii;
}

int main()
{
	int a,b,result;
	scanf("%d%d",&a,&b);
	if(cal(a,b,&result))
	{
		printf("%d/%d=%d",a,b,result);
	}
	return 0;
}
