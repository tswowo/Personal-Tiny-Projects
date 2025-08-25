#include<stdio.h>
int pp(int p,int day);
int main()
{
	int day,peach;
	scanf("%d",&day);
	peach=pp(1,day);
	printf("%d",peach);
	return 0;
}
int pp(int p,int day)
{
	if(p==day)return 1;
	else return 2*(pp(p+1,day)+1);
}
