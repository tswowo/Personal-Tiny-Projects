#include"stdio.h"
main(){//231121200602122150
	long long int fff;
	int year,month,day;
	printf("请输入18位身份证号：");
	scanf("%lld",&fff);
	fff/=10000;
	day=fff%100;
	fff/=100;
	month=fff%100;
	fff/=100;
	year=fff%10000;
	printf("出生年为%d，月为%d，日为%d。",year,month,day);
}
