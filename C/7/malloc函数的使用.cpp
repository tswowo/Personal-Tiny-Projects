#include<stdio.h>
#include<string.h>
#include<stdlib.h>//������malloc���ڴ���غ��� 
int main()
{
	int *x;
	x=(int*)malloc(sizeof(int));
	//malloc�ķ���������ָ�룬��ָ�����������֣�����Ҫ����ǿ��ת�� 
	*x=1;
	printf("%d\n",*x);
	
	//���õĿռ����ʹ��free()�ͷ�
	free(x); 
	
	int *p,i;//malloc��������ռ�����˵ 
	p=(int *)malloc(sizeof(int)*10);
	for(i=0;i<10;i++)
		p[i]=i*i;
	for(i=0;i<10;i++)
		printf("%5d",p[i]);

}
