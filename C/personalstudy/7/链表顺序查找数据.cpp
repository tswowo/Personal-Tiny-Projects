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
	printf("���������ݸ�����");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		p=(st*)malloc(sizeof(st));
		printf("�������%d�����ݣ�",i+1);
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
	printf("����������ҵ����ݣ�");
	scanf("%d",&n);
	p=head;
	while(p->next!=NULL)
	{
		if(p->num==n)break;
		else p=p->next;
	}
	if(p->num==n)printf("���ҳɹ�");
	else if(p->num!=n)printf("����ʧ��"); 
	return 0;
}
