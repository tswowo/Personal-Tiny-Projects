#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

class node{
	public:
		bool isend;
		unordered_map<char,node*>children;
		node(){
			isend=false;
		}
};

class trie{
	private:
		node *root;
	public:
		trie(){
			root=new node();
		}
		void insert(const string&s)
		{
			node* q=root;
			for(auto&ch:s)
			{
				if(q->children.count(ch)==0)
					q->children[ch]=new node();
				q=q->children[ch];
			}
			q->isend=true;
		}
		bool search(const string&s)//��������ĵ��� 
		{
			node*p=searchPre(s);
			return p!=nullptr&&p->isend;
		}
		bool searchStart(const string&s)//��ǰ׺ 
		{
			return searchPre(s)!=nullptr;
		}
	private:
		node* searchPre(const string&s)
		{
			node* q=root;
			for(auto&ch:s)
			{
				if(q->children.count(ch)==0)
					return nullptr;
				q=q->children[ch];
			}
			return q;
		}
};

int main()
{
	
}
