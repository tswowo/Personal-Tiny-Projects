#include<stdio.h>
//Ĭ�϶�����Ǿֲ�����(�Զ�����auto register) 
//ȫ�ֱ�������̬����extern�� 
void f(); /*����˵��*/
int main()
{
	int i;

	for(i=1;i<=5;i++)
		f(); /*��������*/		
}
void f() /*��������*/
{
	static int k=0;
	k++;
	printf("%d\n",k);
}

