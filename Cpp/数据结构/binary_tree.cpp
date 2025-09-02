#include<iostream>

class byt{
	private:
		class bytNode;
		typedef class bytNode *position;
		typedef class bytNode *bytTree;
		class bytNode{
			public:
				int key;
				int val;
				position left;
				position right;
				int exist;
				bytNode(int key,int val){
					this->key=key;
					this->val=val;
					exist=1;
					left=right=nullptr;
				}
		};
		bytTree root;
		size_t _size;
		position insertHelper(position p,int key,int val)
		{
			if(p==nullptr)
			{
				p=new bytNode(key,val);
				this->_size++;
				return p;
			}
			if(key==p->key)
			{
				p->val=val;
				if(p->exist==0)
				{
					this->_size++;
					p->exist=1;
				}
			}
			else if(key<p->key)
				p->left=insertHelper(p->left,key,val);
			else
				p->right=insertHelper(p->right,key,val);
			return p;
		}
		position deleteHelper(position p,int key)
		{
			if(p==nullptr)
				return p;
			if(p->key==key)
			{
				p->exist=0;
				this->_size--;
			}
			else if(key<p->key)
				p->left=deleteHelper(p->left,key);
			else
				p->right=deleteHelper(p->right,key);
			return p;
		}
	public:
		byt()
		{
			root=nullptr;
			_size=0;
		}
		position insert(int key,int val)
		{
			return root=insertHelper(root,key,val);
		}
		void erase(int key)
		{
			deleteHelper(root,key);
		}
		size_t size()
		{
			return this->_size;
		}
		int count(int key)
		{
			return find(key)!=nullptr?1:0;
		}
		position find(int key)
		{
			position p=root;
			while(p!=nullptr&&p->key!=key)
			{
				if(key<p->key)
					p=p->left;
				else
					p=p->right;
			}
			return p?p->exist==1?p:nullptr:nullptr;
		}
		int& operator[](int key)
		{
			if(count(key)==0)
				insert(key,int());
			position p=root;
			while(p!=nullptr&&p->key!=key)
			{
				if(key<p->key)
					p=p->left;
				else
					p=p->right;
			}
			return p->val;
		}
};

int main()
{
	byt a;
	std::cout<<a.size()<<std::endl;
	a.insert(1,2);
	std::cout<<a.count(1)<<std::endl;
	std::cout<<a[1]<<std::endl;
	a[2]=3;
	std::cout<<a[2]<<std::endl;
	return 0;
}
