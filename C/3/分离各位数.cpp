#include"stdio.h"
#include<ctype.h>
main(){
	int num,a;
	printf("������һ��������");
	scanf("%d",&num);
	printf("��������ֺ����Ϊ��\n");
	while(num>0){
		a=num%10;
		num/=10;
		printf("%d\n",a);
	}
}
