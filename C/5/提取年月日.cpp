#include<stdio.h>
void acc(int y){
	if(y%400==0){
		printf("%d是闰年",y);
	}
	if(y%400!=0&&y%100==0){
		printf("%d不是闰年",y);
	}
	if(y%4==0&&y%100!=0){
		printf("%d不是闰年",y);
	}
	if(y%4!=0){
		printf("%d不是闰年",y);
	}
}

int main(){
	int y,m,d;
	scanf("%d%d%d",&y,&m,&d);
	if((m>0||m<=12)&&d>0&&d<=31){
		acc(y);
	}
	else{
		printf("请规范输入");
	}
}
