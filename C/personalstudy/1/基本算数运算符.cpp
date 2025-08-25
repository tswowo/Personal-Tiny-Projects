#include<stdio.h>
/*main(){
	int a,b;
	float c,e,d;
	a=2;
	b=3;
	c=1.5;
	d=2.5;
	e=34/5.0;
	printf("%f",e);
}*/

#include<math.h>
main(){/*ËÄÉáÎåÈë 
	int a,b;
	a=round(3.14);
	b=int(3.14+0.5);
	printf("%f",a);
	printf("%f",b);*/
	int a,b;
	a=12345;
	a=(int)a/100*100;
	printf("%d\n",a);
	b=0;
	printf("%d\n",b++);
	printf("%d\n",++b);
	printf("%d\n",b); 
}
