#include"stdio.h"
#include<ctype.h>
main(){
	int num,a;
	printf("请输入一个整数：");
	scanf("%d",&num);
	printf("该整数拆分后的数为：\n");
	while(num>0){
		a=num%10;
		num/=10;
		printf("%d\n",a);
	}
}
