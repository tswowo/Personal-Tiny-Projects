#include<iostream>
using namespace std;
//��Ļ������� 
class point
{
	private:
		int xPos;//
	public:
		//���캯��1
//		point(int x=10,int y=2)
//		{
//			xPos=x;
//			yPos=y;
//		}
		point(int x=-10,int y=-10):xPos(x),yPos(y){}
		//���캯��2 
		point(point &other)
		{
			this->xPos=other.xPos;
			this->yPos=other.yPos;
		}
		//��ֵ���
		point& operator=(const point &other)
		{
			if(this!=&other)
			{
				xPos=other.xPos;
				yPos=other.yPos;
			}
			return *this;
		}
		void printPoint()
		{
			cout<<"xPos:"<<xPos<<endl<<"yPos:"<<yPos<<endl;//���ڳ�Ա���ڷ��� 
		}
		void addPoint();
		void updatePoint(int x,int y);
	private:
		int yPos;
};

void point::addPoint()//������ʵ�����ڳ�Ա���� �����������:: 
{
	xPos++;
	yPos++;
}

void point::updatePoint(int x,int y)
{
	xPos=x;
	yPos=y;
}

int main()
{
	point a(1,1);
	point b(a);
	point A=b;
	A.printPoint();
	A.addPoint();
	A.printPoint();
	A.updatePoint(-1,-2);
	A.printPoint();
	cout<<endl;
	point* test=new point;
	test->printPoint();
	*test=a;
	test->printPoint();
	delete test;
}
