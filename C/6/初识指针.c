#include<stdio.h>
int main(){
	int a=3;
	int *b=&a;
	int *c=b;
	printf("b=%d\n",b);
	printf("b=%p\n",b);
	printf("*b=%d\n",*b);
	printf("*b=%p\n",*b);
	
	printf("c=%d\n",c);
	printf("c=%p\n",c);
	printf("*c=%d\n",*c);
	printf("*c=%p\n",*c);
}
/*
ָ�������һ������ı����� 
������ʱҪʹ��*��
��������ʱ��
��������޸���ָ��ı�����Ҫ��*��
��������޸�ָ�벻��Ҫ��*
*/
