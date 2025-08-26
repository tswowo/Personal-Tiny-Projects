#include"stdio.h"
main(){
	printf("请输入两个整数：");
	int a,b,s,c;
	scanf("%d%d",&a,&b);
	fflush(stdin);
	printf("\n1.+\t2.-\t3.*\t4./\n");
	scanf("%d",&s);
	switch(s){
		case 1:
			c=a+b;
			printf("%d+%d=%d",a,b,c);
			break;
		case 2:
			c=a-b;
			printf("%d-%d=%d",a,b,c);
			break;
		case 3:
			c=a*b;
			printf("%d*%d=%d",a,b,c);
			break;
		case 4:
			c=a/b;
			printf("%d/%d=%d",a,b,c);
			break;
		default:
			printf("请输入1-4内的整数");
			break;
	}
}
