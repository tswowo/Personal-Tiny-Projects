#include<stdio.h>
main(){
	int a,b,c,d;
	a=50;
	b=(a>70|a<100);
	c=(a>70&a<100);
	d=!!!(a>70&a<100);
	printf("%d\n",b);
	printf("%d\n",c);
	printf("%d\n",d);
	a=0;
	b=!a;
	c=!a>=0;
	d=!(a>5);
	printf("%d\n",b);
	printf("%d\n",c);
	printf("%d\n",d);
}
