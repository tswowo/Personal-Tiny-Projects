#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
	int num;
	char name[20];
	int score;
	
	struct student *next;
}student; 

int main()
{
	struct student *head,*p,*q;//ָ��ͷ��㣬qָ��ԭβ��㣬pָ���½�� 
	int n;
	printf("������ѧ��������");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		p=(student*)malloc(sizeof(student));
		printf("�������%d������:",i);
		scanf("%d",&p->num);
		if(i==0)
		{
			head=p;
			q=p;
		}
		else
		{
			q->next=p;
			q=p;
		}
		q->next=NULL; 
	}
	p=head;
	for(int i=0;i<n;i++)
	{
		printf("%d ",p->num);
		p=p->next;
	}
	return 0;
}
