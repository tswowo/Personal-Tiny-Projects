#include<iostream>
#include<algorithm>

class avl{
	private:
		class avlNode;
		typedef avlNode* avlTree;
		typedef avlNode* position;
		class avlNode{
			public:
				int key;
				int val;
				position left;
				position right;
				int height;
				avlNode(int key,int val)
				{
					this->key=key;
					this->val=val;
					height=1;
					left=right=nullptr;
				}
				void updateHeight()
				{
					height=std::max(avl::getHeight(left),avl::getHeight(right))+1;
				}
		};
		avlTree root;
		size_t _size;
		position leftRotate(position a)//to solve RR
		{
			position tmp=a->right;
			a->right=tmp->left;
			tmp->left=a;
			return tmp;
		}
		position rightRotate(position a)//to solve LL
		{
			position tmp=a->left;
			a->left=tmp->right;
			tmp->right=a;
			return tmp;
		}
		position leftRightRotate(position a)//to solve LR
		{
			a->left=leftRotate(a->left);
			return rightRotate(a);
		}
		position rightLeftRotate(position a)//to solve RL
		{
			a->right=rightRotate(a->right);
			return leftRotate(a);
		}
		static int getHeight(position x)
		{
			return x!=nullptr?x->height:0;
		}
		int getBalance(position x)
		{
			if(x==nullptr)
				return 0;
			return getHeight(x->left)-getHeight(x->right);
		}
		position insertHelper(position p,int key,int val)
		{
			if(p==nullptr)
			{
				p=new avlNode(key,val);
				_size++;
				return p;
			}
			if(p->key==key)
				p->val=val;
			else if(key<p->key)
				p->left=insertHelper(p->left,key,val);
			else
				p->right=insertHelper(p->right,key,val);
			p->updateHeight();
			int balance=getBalance(p);
			if(balance>1)
			{
				if(key<p->left->key)
					p=rightRotate(p);
				else if(key>p->left->key)
					p=leftRightRotate(p);
			}
			else if(balance<-1)
			{
				if(key>p->right->key)
					p=leftRotate(p);
				else if(key<p->right->key)
					p=rightLeftRotate(p);
			}
			return p;
		}
		position getMinNode(position p)
		{
			while(p!=nullptr&&p->left!=nullptr)
				p=p->left;
			return p;
		}
		position deleteHelper(position p,int key)
		{
			if(p==nullptr)
				return nullptr;
			if(key<p->key)
				p->left=deleteHelper(p->left,key);
			else if(key>p->key)
				p->right=deleteHelper(p->right,key);
			else if(p->key==key)
			{
				_size--;
				if(p->left==nullptr&&p->right==nullptr)
					return nullptr;
				else if(p->left==nullptr&&p->right!=nullptr)
				{
					position tmp=p->right;
					delete p;
					return tmp;
				}
				else if(p->left!=nullptr&&p->right==nullptr)
				{
					position tmp=p->left;
					delete p;
					return tmp;
				}
				else
				{
					position tmp=getMinNode(p->right);
					p->key=tmp->key;
					p->val=tmp->val;
					p->right=deleteHelper(p->right,tmp->key);
				}
			}
	        if(p==nullptr)
	            return nullptr;
	        p->updateHeight();
	        int balance=getBalance(p);
	        if(balance>1&&getBalance(p->left)>0)
	            p=rightRotate(p);
	        else if(balance>1&&getBalance(p->left)<0)
	            p=leftRightRotate(p);
	        else if(balance<-1&&getBalance(p->right)<0)
	            p=leftRotate(p);
	        else if(balance<-1&&getBalance(p->right)>0)
	            p=rightLeftRotate(p);
			return p;
		}
	public:
		avl(){
			root=nullptr;
			_size=0;
		}
		void insert(int key,int val)
		{
			root=insertHelper(root,key,val);
		}
		void erase(int key)
		{
			root=deleteHelper(root,key);
		}
		position find(int key)
		{
			position p=root;
			while(p!=nullptr&&p->key!=key)
			{
				if(key<p->key)
					p=p->left;
				else if(key>p->key)
					p=p->right;
			}
			return p;
		}
		int count(int key)
		{
			position tmp=find(key);
			return tmp==nullptr?0:1;
		}
		int& operator[](int key)
		{
			position tmp=find(key);
			if(tmp==nullptr)
			{
				insert(key,int());
				tmp=find(key);
			}
			return tmp->val;
		}
		size_t size()const
		{
			return _size;
		}
};

int main()
{
	avl a;
	a.insert(1,2);
	std::cout<<a.size()<<std::endl;
	std::cout<<a.count(1)<<std::endl;
	std::cout<<a[1]<<std::endl;
	a[2]=3;
	std::cout<<a[2]<<std::endl;
	return 0;
}
