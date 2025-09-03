#include<iostream>
using namespace std;

typedef struct listNode{
	int val;
	struct listNode* next;
	listNode(int val=int()):val(val),next(nullptr){}
}node,*nodePtr;

nodePtr createList(int n)
{
	cout<<"请输入"<<n<<"个数字:\n"; 
	nodePtr head=new listNode;
	nodePtr tail=head;
	while(n--)
	{
		int tmp;cin>>tmp;
		tail->next=new node(tmp);
		tail=tail->next;
	}
	return head;
}

void printList(nodePtr head)
{
	head=head->next;
	cout<<"打印链表:\n";
	while(head!=nullptr)
	{
		cout<<head->val<<'\n';
		head=head->next;
	}
	cout<<'\n';
}

nodePtr getUnset(nodePtr a,nodePtr b,int*ans)
{
	nodePtr head=a;
	nodePtr tail=head;
	nodePtr headB=b;
	a=a->next;
	b=b->next;
	delete headB;
	*ans=0;
	while(a&&b)
	{
		if(a->val==b->val)
		{
			nodePtr tmpA=a;
			a=a->next;
			delete tmpA;
			nodePtr tmpB=b;
			b=b->next;
			delete tmpB;
		}
		else if(a->val<b->val)
		{
			tail->next=a;
			a=a->next;
			tail=tail->next;
			(*ans)++;
		}
		else
		{
			tail->next=b;
			b=b->next;
			tail=tail->next;
			(*ans)++;
		}
	}
	if(a!=nullptr)
	{
		tail->next=a;
		tail=tail->next;
		while(tail!=nullptr)
		{
			(*ans)++;
			tail=tail->next;
		}
	}
	if(b!=nullptr)
	{
		tail->next=b;
		tail=tail->next;
		while(tail!=nullptr)
		{
			(*ans)++;
			tail=tail->next;
		}
	}
	return head;
}

int main()
{
	auto a=createList(5);
	auto b=createList(5);
	printList(a);
	printList(b);
	int cnt=0;
	auto unSet=getUnset(a,b,&cnt);
	printList(unSet);
	cout<<"差集大小:"<<cnt;
	return 0;
}
