#include<stdio.h>
int main(){
	printf("请输入两个待比较数字：");
	int num1,num2,*a,*b;
	scanf("%d%d",&num1,&num2);
	a=&num1;
	b=&num2;
	if(*a>*b){
		a=&num2;b=&num1;
	}
	printf("%d,%d",*a,*b);
}
