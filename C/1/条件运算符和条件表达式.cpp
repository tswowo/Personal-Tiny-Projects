#include<stdio.h>
main(){
	int a,b,c;
	a=10;
	b=3;
	c=3>2?a+3:10;//���ı�a��ֵ����3>2������c=a+3��ֵ 
	printf("%d\n",a);
	printf("%d\n",c);
	c=3>2?a=a+3:10;//�ı�a��ֵΪa+3����3>2������c=a+3��ֵ 
	printf("%d\n",a);
	printf("%d\n",c);
}
