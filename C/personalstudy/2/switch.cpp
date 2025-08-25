#include<stdio.h>
int main(){
	printf("请输入一个整数：");
	int a;
	scanf("%d",&a);
	switch(a){
		case 5:
			printf("这个整数是5");
			break;
		case 4:
			printf("这个整数是4");
			break;
		case 3:
			printf("这个整数是3");
			break;
		case 2:
			printf("这个整数是2");
			break;
		case 1:
			printf("这个整数是1"); 
			break;
		default:
			printf("这个整数不是1或2或3或4或5");
	}
}
