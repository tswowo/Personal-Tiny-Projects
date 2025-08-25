#include<stdio.h>
int main(){
	int a,b;
	printf("请输入两个整数：\n");
	scanf("%d%d",&a,&b);
	if(a>=b){
		if(a>b)
		{printf("%d,%d",a,b);}
		else{printf("==");}
	}
	else{printf("%d%d",b,a);
	}
	




	/*if(a>=b){
	c=a;a=b;b=c;}else{
	}printf("a=%d\tb=%d",a,b);*/
}
