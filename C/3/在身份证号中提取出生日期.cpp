#include"stdio.h"
main(){//231121200602122150
	long long int fff;
	int year,month,day;
	printf("������18λ���֤�ţ�");
	scanf("%lld",&fff);
	fff/=10000;
	day=fff%100;
	fff/=100;
	month=fff%100;
	fff/=100;
	year=fff%10000;
	printf("������Ϊ%d����Ϊ%d����Ϊ%d��",year,month,day);
}
