#include<stdio.h>

union test
{
	int a[3];//3*4=12个字节
	float b;//4个字节 
	char c;//1个字节 
};

typedef union test ut;
//int 和float对内存空间的使用规则不同。所以，一个共用体变量，当其做整型数组使用时，就不能做实型变量使用。

//节约空间 
int main()
{
	ut first;
	//作为整型数组使用:
	for(int i=0;i<3;i++)
		first.a[i]=i+1;
		
	printf("a[]={%d,%d,%d}\n",first.a[0],first.a[1],first.a[2]);
	
	//作为实数使用:
	first.b=1.2;
	printf("b=%f\n",first.b);
	
	//作为字符使用:
	first.c='G';
	printf("%c\n",first.c);
	return 0;
}
