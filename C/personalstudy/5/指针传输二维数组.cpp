#include<stdio.h>
void arraySum(int num[][4],int *p1,int *p2,int *p3);
int main()
{
	int a[3][4]={{1,2,3,4},{4,5,6,7},{6,7,8,9}};
	int one,two,three;
	arraySum(a,&one,&two,&three);
	printf("one is %d\ntwo is %d\nthree is %d\n",one,two,three);
}

void arraySum(int num[][4],int *p1,int *p2,int *p3)//求每行之和 
{
	*p1=*p2=*p3=0;
	for(int i=0;i<4;i++)
	{
		*p1+=num[0][i];
		*p2+=num[1][i];
		*p3+=num[2][i];
	}
}
