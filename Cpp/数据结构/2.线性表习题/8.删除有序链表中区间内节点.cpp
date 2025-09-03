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

void deleteRangeInList(nodePtr head,int left,int right)
{
	nodePtr prev=head;
	nodePtr cur=head->next;
	while(cur!=nullptr)
	{
		if(left<cur->val&&cur->val<right)
		{
			nodePtr tmp=cur;
			prev->next=cur->next;
			cur=cur->next;
			delete tmp;
		}
		else
		{
			prev=cur;
			cur=cur->next;
		}
	}
}

int main()
{
	auto p=createList(10);
	printList(p);
	deleteRangeInList(p,1,5);
	printList(p);
	return 0;
}
