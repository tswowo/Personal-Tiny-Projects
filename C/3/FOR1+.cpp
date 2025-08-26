#include"stdio.h"
main(){//1-1/2+1/3-...-1/n
	int n;
	printf("请输入整数n的值：");
	scanf("%d",&n);
	float a,b=1,c=1,e,f,g=0;
	while(c<=n){
		c+=2;
		a=1/c;
		b+=a;
		printf("\n%f",b);
	}
	printf("\n");
	while(g<=n){
		g+=2;
		e=1/g;
		f-=e;
		printf("\n%f",f);
	}
	f=b+f;
	printf("\n%f",f);
}
