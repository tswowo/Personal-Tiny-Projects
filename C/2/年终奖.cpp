#include<stdio.h>
#include<ctype.h>
main(){
	int money,p1,p2,p3,p4;
	printf("����������");
	scanf("%d",&money);
	p1=money+(money-1000)*0.05;
	p2=p1+(p1-2000)*0.05;
	p3=p2+(p2-3000)*0.10;
	p4=p3+(p3-4000)*0.15;
	if(money<=0||isdigit(money))
		printf("��������ȷ������");
	else if(money<1000)
		printf("���ս����Ϊ��%d",p1);
	else if(money<2000)
		printf("���ս����Ϊ��%d",p2);
	else if(money<3000)
		printf("���ս����Ϊ��%d",p3);
	else
		printf("���ս����Ϊ��%d",p4);
}


