#include<stdio.h>
int main(){
	printf("�������������Ƚ����֣�");
	int num1,num2,*a,*b;
	scanf("%d%d",&num1,&num2);
	a=&num1;
	b=&num2;
	if(*a>*b){
		a=&num2;b=&num1;
	}
	printf("%d,%d",*a,*b);
}
