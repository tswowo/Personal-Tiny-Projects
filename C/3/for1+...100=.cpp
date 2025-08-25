#include<stdio.h>
main(){
	int a,b;
	b=0;
	for(a=0;a<=100;a++){
		b+=a;
		printf("%d\t%d\n",a,b);
	}
	printf("\n%d",b);
}
