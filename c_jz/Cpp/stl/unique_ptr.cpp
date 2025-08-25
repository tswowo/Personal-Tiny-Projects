#include<iostream>
#include<memory>
using std::unique_ptr;

class st{
	private:
		int x,y;
	public:
		st(int x,int y):x(x),y(y){};
		st&operator =(const st&other)
		{
			x=other.x;
			y=other.y;
			return *this;
		}
		~st()
		{
			std::cout<<"对象被释放~~\n";
		}
		friend std::ostream& operator<<(std::ostream&os,const st&obj)
		{
			os<<obj.x<<' '<<obj.y<<std::endl;
		}
};

int main()
{
	getchar();
	unique_ptr<st>p(new st(1,2));
	std::cout<<*p;
	p=nullptr;
	unique_ptr<st> p1(new st(2,3));
	unique_ptr<st> p2(new st(3,4));
	p1=move(p2);
	
	std::cout<<"程序执行结束";
	getchar();
	return 0;
}
