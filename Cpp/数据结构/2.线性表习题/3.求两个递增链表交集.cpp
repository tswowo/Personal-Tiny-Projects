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

nodePtr getSet(nodePtr a,nodePtr b)
{
	if(a==nullptr)
		return b;
	if(b==nullptr)
		return a;
	nodePtr head=a;
	nodePtr tail=head;
	nodePtr headB=b;
	a=a->next;
	b=b->next;
	delete headB;
	while(a&&b)
	{
		if(a->val==b->val)
		{
			tail->next=a;
			a=a->next;
			b=b->next;
			tail=tail->next;
		}
		else if(a->val<b->val)
		{
			nodePtr tmp=a;
			a=a->next;
			delete tmp;
		}
		else
		{
			nodePtr tmp=b;
			b=b->next;
			delete tmp;
		}
	}
	while(a!=nullptr)
	{
		nodePtr tmp=a;
		a=a->next;
		delete tmp;
	}
	while(b!=nullptr)
	{
		nodePtr tmp=b;
		b=b->next;
		delete tmp;
	}
	tail->next=nullptr;
	return head;
}

int main()
{
	auto a=createList(10);
	auto b=createList(5);
	printList(a);
	printList(b);
	auto mergeSet=getSet(a,b);
	printList(mergeSet);
	return 0;
}
