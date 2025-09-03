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

void splitBySign(nodePtr origin,nodePtr*pos,nodePtr*neg)
{
	nodePtr head=origin;
	nodePtr posTail=*pos;
	nodePtr negTail=*neg;
	while(origin!=nullptr)
	{
		if(origin->val>0)
		{
			posTail->next=origin;
			posTail=posTail->next;
		}
		else if(origin->val<0)
		{
			negTail->next=origin;
			negTail=negTail->next;
		}
		origin=origin->next;
	}
	posTail->next=nullptr;
	negTail->next=nullptr;
	delete head;
}

int main()
{
	auto a=createList(10);
	printList(a);
	auto b=createList(0);
	auto c=createList(0);
	splitBySign(a,&b,&c);
	printList(b);
	printList(c);
	return 0;
}
