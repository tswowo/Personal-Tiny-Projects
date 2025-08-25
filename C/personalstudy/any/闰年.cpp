#include<stdio.h>
int main()
{
	int year;
	scanf("%d",&year);
	if(year%100==0&&year%400!=0)
		printf("%d不是闰年",year);
	else if(year%4==0)
		printf("%d是闰年",year);
	else
		printf("%d不是闰年",year);
	return 0;
}
