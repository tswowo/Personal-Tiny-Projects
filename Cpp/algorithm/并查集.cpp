#include<iostream>
#include<vector>
using namespace std;

class bcj{
	private:
		vector<int>root;
		vector<int>nums;
		int size;
	public:
		bcj(const vector<int>&a)
		{
			
			this->size=a.size();
			root.resize(a.size());
			for(int i=0;i<root.size();i++)
				root[i]=i;//初始指向自己，自成集合 
			nums=a;
		}
		bcj&operator =(const bcj&other)
		{
			root=other.root;
			nums=other.nums;
			size=other.size;
			return *this;
		}
		friend ostream& operator <<(ostream&os,bcj& obj)
		{
			for(int i=0;i<obj.size;i++)
				os<<"nums["<<i<<"] = "<<obj.nums[i]<<" 's root is "<<obj.find(obj.root[i])<<endl;
			os<<"print end...\n";
			return os;
		}
		int find(int x)
		{
			if(root[x]!=x)
				root[x]=find(root[x]);//路径压缩 
			return root[x];
		}
		void Union(int x,int y)
		{
			int posx=find(x);
			int posy=find(y);
			if(posx>posy)
				root[posy]=posx;
			else if(posx<posy)
				root[posx]=posy;
		}
};

int main()
{
	bcj Mybcj({1,2,3,4,5});
	cout<<Mybcj;
	Mybcj.Union(2,3);
	cout<<Mybcj;
	Mybcj.Union(1,2);
	cout<<Mybcj;
	Mybcj.Union(3,4);
	cout<<Mybcj;
	return 0;
}
