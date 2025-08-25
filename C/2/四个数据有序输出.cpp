#include"stdio.h"
main(){
	int a,b,c,d,e;
	printf("请输入四个整数：");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(b>a){e=a,a=b,b=e;}
	if(c>a){e=a,a=c,c=e;}
	if(d>a){e=a,a=d,d=e;}
	if(c>b){e=b,b=c,c=e;}
	if(d>b){e=b,b=d,d=e;}
	if(d>c){e=d,d=c,c=e;}
	printf("%d,%d,%d,%d",a,b,c,d);
}
