#include<stdio.h>
void acc(int y){
	if(y%400==0){
		printf("%d������",y);
	}
	if(y%400!=0&&y%100==0){
		printf("%d��������",y);
	}
	if(y%4==0&&y%100!=0){
		printf("%d��������",y);
	}
	if(y%4!=0){
		printf("%d��������",y);
	}
}

int main(){
	int y,m,d;
	scanf("%d%d%d",&y,&m,&d);
	if((m>0||m<=12)&&d>0&&d<=31){
		acc(y);
	}
	else{
		printf("��淶����");
	}
}
