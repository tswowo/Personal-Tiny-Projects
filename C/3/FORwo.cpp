#include"stdio.h"
main(){//1-1/2+1/3-...-1/100
	//1+1/3+1/5+...+1/99
	int n;
	printf("请输入整数n的值：");
	scanf("%d",&n);
	long long int numa,dena,acca,den1;
	numa=1;
	dena=1;
	acca=1;
	while(acca<=n){
		acca+=2;
		den1=dena;
		numa=numa*acca;
		dena=dena*acca;
		numa+=den1;
		printf("acca=%d,den1=%d,numa=%d,dena=%d\n",acca,den1,numa,dena);
	}
	printf("\n%d/%d\n",numa,dena);
	
	long long int numb,denb,accb,den2;
	numb=1;
	denb=2;
	accb=2;
	while(accb<=n){
		accb+=2;
		den2=denb;
		numb=numb*accb;
		denb=denb*accb;
		numb+=den2;
		printf("accb=%d,den2=%d,numb=%d,denb=%d\n",accb,den2,numb,denb);
	}
	printf("\n%d/%d\n",numb,denb);
	long long int num,den;
	num=numa*denb-dena*numb;
	den=dena*denb;
	
	float reason;
	reason=1.0*num/den;
	printf("%d/%d\n%lf",num,den,reason);
}
