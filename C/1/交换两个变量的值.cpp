#include"stdio.h"
main(){
	int a,b,c;
	printf("请输入两个整数：");
	scanf("%d%d",&a,&b);
	c=a;
	a=b;
	b=c;
	printf("\na=%d\tb=%d",a,b);
}
