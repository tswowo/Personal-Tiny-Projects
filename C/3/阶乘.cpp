#include"stdio.h"
main(){
	int a,b;
	printf("请输入：");
	scanf("%d",&a);
	if(a==0){
		printf("1");
	}
	else if(a>0&&a<=12){
		b=1;
		for(;a>=1;a--){
			b*=a;
		}
		printf("\n%d",b);
	}
	else{
		printf("请输入一个小于十三的正整数");
	}
}
