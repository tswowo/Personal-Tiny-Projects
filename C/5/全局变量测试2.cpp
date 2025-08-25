#include<stdio.h>
int x,y;
void swap()
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
int main()
{
	x=1;y=2;
	printf("x=%d y=%d\n",x,y);
	swap();
	printf("x=%d y=%d\n",x,y);
}
