#include<stdio.h>

union test
{
	int a[3];//3*4=12���ֽ�
	float b;//4���ֽ� 
	char c;//1���ֽ� 
};

typedef union test ut;
//int ��float���ڴ�ռ��ʹ�ù���ͬ�����ԣ�һ���������������������������ʹ��ʱ���Ͳ�����ʵ�ͱ���ʹ�á�

//��Լ�ռ� 
int main()
{
	ut first;
	//��Ϊ��������ʹ��:
	for(int i=0;i<3;i++)
		first.a[i]=i+1;
		
	printf("a[]={%d,%d,%d}\n",first.a[0],first.a[1],first.a[2]);
	
	//��Ϊʵ��ʹ��:
	first.b=1.2;
	printf("b=%f\n",first.b);
	
	//��Ϊ�ַ�ʹ��:
	first.c='G';
	printf("%c\n",first.c);
	return 0;
}
