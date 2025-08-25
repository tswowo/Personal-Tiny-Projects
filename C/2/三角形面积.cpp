#include"stdio.h"
#include"math.h"
main(){
	float a,b,c,p,C,s;
	printf("请输入三个实数：");
	scanf("%f%f%f",&a,&b,&c);
	if(a+b>c&a-b<c){
		p=(a+b+c)/2;
		C=a+b+c;
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		printf("\n三角形的周长为：%f，面积为：%f",C,s);
	}
	else{
		printf("输入的%f,%f,%f不能构成三角形",a,b,c);
	}
}
