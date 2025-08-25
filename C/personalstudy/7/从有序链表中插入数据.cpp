#include<stdio.h>
#include<stdlib.h>

typedef struct Link{
	int num;
	struct Link *last;
	struct Link *next;
}*link;

link create(link last,int x)
{
	link p=(link)malloc(sizeof(link));
	p->num=x;
	p->last=last;
	p->next=NULL;
	return p;
}

int main()
{
	link head,q,p,temp;
	int innum;
	q=head=create(NULL,0);
	
	printf("请输入原始链表：(输入0以终止输入)\n");
	scanf("%d",&innum);
	while(innum!=0)
	{
		q->next=create(q,innum);
		q=q->next;
		scanf("%d",&innum);
	}
	q->next=create(q,0);
	q=q->next;
	printf("over\n");
	
	printf("请输入待插入数字：(输入0以终止输入)\n");
	p=head->next;
	scanf("%d",&innum);
	while(innum!=0)
	{
		while(p->num<innum&&p!=q)
		{
			p=p->next;
		}
		if(p!=q)
		{
			temp=create(p->last,innum);
			printf("ONE\n");
			temp->next=p;
			temp->last->next=temp;
			temp->next->last=temp;
		}
		else if(p==q)
		{
			printf("TWO\n");
			temp=create(q->last,innum);
			temp->next=q;
			temp->last->next=temp;
			q->last=temp;
		}
		scanf("%d",&innum);
	}
	printf("over\n");
	for(p=head->next;p!=q;p=p->next)
		printf("%d ",p->num);
	return 0;
}
