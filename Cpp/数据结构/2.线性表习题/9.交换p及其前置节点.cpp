#include<iostream>
using namespace std;

typedef struct listNode{
	int val;
	struct listNode* prev;
	struct listNode* next;
	listNode(int val=int()):val(val),prev(nullptr),next(nullptr){}
}node,*nodePtr;

nodePtr createList(int n)
{
	cout<<"请输入"<<n<<"个数字:\n"; 
	nodePtr head=new listNode;
	head->prev=head;
    head->next=head;
	nodePtr tail=head;
	while(n--)
	{
		int tmp;cin>>tmp;
		tail->next=new node(tmp);
		tail->next->prev=tail;
		tail->next->next=head;
		tail=tail->next;
		head->prev=tail;
	}
	return head;
}

void printList(nodePtr head)
{
	nodePtr cur=head->next;
	cout<<"打印链表:\n";
	while(head!=cur)
	{
		cout<<cur->val<<'\n';
		cur=cur->next;
	}
	cout<<'\n';
}

void exchangeCurwithPrior(nodePtr head,nodePtr p)
{
    if(!p||p==head||p->prev==head)
        return;
    nodePtr prev=p->prev;
    nodePtr prevPrev=prev->prev;
    nodePtr next=p->next;
    
	prevPrev->next=p;
	next->prev=prev;
	
	prev->prev=p;
	prev->next=next;
	
	p->prev=prevPrev;
	p->next=prev;
}

int main()
{
	auto p=createList(10);
	printList(p);
	exchangeCurwithPrior(p,p->next->next);
	printList(p);
	return 0;
}
