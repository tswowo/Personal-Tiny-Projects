#include"stdio.h"
main(){
	int a,b;
	printf("�����룺");
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
		printf("������һ��С��ʮ����������");
	}
}
