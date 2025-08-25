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
	struct student *head,*p,*q;//指向头结点，q指向原尾结点，p指向新结点 
	int n;
	printf("请输入学生个数：");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		p=(student*)malloc(sizeof(student));
		printf("请输入第%d个数字:",i);
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
