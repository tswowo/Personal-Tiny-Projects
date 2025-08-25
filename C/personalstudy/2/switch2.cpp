#include<stdio.h>
int main(){
	printf("请输入一个整数：");
	int a;
	scanf("%d",&a);
	switch(a){
		case 1:
		case 3:
		case 5:
		case 7:
		case 9:
			printf("这个数是奇数\n");
			break;
		default:
			printf("这个数是偶数\n");
		case 2:
			printf("这个数是偶数2\n");
	}
	return 0;
}
