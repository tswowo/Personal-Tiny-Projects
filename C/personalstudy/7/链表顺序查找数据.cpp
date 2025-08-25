#include<stdio.h>
#include<stdlib.h>
struct st
{
	int num;
	
	st *next;
};
int main()
{
	st *head,*q,*p;
	int n;
	printf("请输入数据个数：");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		p=(st*)malloc(sizeof(st));
		printf("请输入第%d个数据：",i+1);
		scanf("%d",&p->num);
		if(i==0)
		{
			head=p;
			q=p;
			head->next=NULL;
		}
		else if(i!=0)
		{
			q->next=p;
			q=p;
			q->next=NULL;
		}
	}
	printf("请输入想查找的数据：");
	scanf("%d",&n);
	p=head;
	while(p->next!=NULL)
	{
		if(p->num==n)break;
		else p=p->next;
	}
	if(p->num==n)printf("查找成功");
	else if(p->num!=n)printf("查找失败"); 
	return 0;
}
