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

void reverseList(nodePtr p)
{
	nodePtr head=p;
	p=p->next;
	head->next=nullptr;
	while(p!=nullptr)
	{
		nodePtr next=p->next;
		p->next=head->next;
		head->next=p;
		p=next;
	}
}

int main()
{
	auto p=createList(5);
	printList(p);
	reverseList(p);
	printList(p);
	return 0;
}
