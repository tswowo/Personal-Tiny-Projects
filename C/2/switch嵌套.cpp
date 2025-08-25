#include<stdio.h>
main(){
	int num,a,b;
	printf("请输入一个整数：");
	scanf("%d",&num);
	if(num%2==0){
		a=1;
	}
	else{
		a=0;
	}
	if(num>0){
		b=1;
	}
	else{
		b=0;
	}
	switch(a){
		case 1:
			switch(b){
				case 0:
					printf ("该数字为小等于0偶数");
					break;
				default:
					printf("该数字为正偶数");
					break;
			}
			break;
		default:
			switch(b){
				case 0:
					printf ("该数字为小等于0的奇数");
					break;
				default:
					printf("该数字为正奇数");
					break;
			}
	}				
}
