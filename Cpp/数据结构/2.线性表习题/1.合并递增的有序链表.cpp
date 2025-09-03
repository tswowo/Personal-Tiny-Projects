#include<iostream>
using namespace std;

typedef struct Node{
	int val;
	struct Node* next;
	Node(int val=int()):val(val),next(nullptr){}
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

nodePtr mergeLists(nodePtr a,nodePtr b)
{
	if(a==nullptr)
		return b;
	if(b==nullptr)
		return a;
	nodePtr head=a;
	nodePtr tail=a;
	nodePtr headB=b;
	a=a->next;
	b=b->next;
	delete headB;
	while(a&&b)
	{
		if(a->val<b->val)
		{
			tail->next=a;
			a=a->next;
		}
		else
		{
			tail->next=b;
			b=b->next;
		}
		tail=tail->next;
	}
	if(a!=nullptr)
		tail->next=a;
	else if(b!=nullptr)
		tail->next=b;
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

int main()
{
	auto a=createList(10);
	auto b=createList(10);
	printList(a);
	printList(b);
	auto combinedList=mergeLists(a,b);
	printList(combinedList);
	return 0;
}
