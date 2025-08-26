#include<stdio.h>
int s1,s2,s3;
void count(int a,int b,int c)
{
	s1=a*b;s2=a*c;s3=b*c;
}
int main()
{
	printf("%d %d %d",s1,s2,s3);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	count(a,b,c);
	printf("%d %d %d",s1,s2,s3);
	return 0;
}
