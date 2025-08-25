#include"stdio.h"
	main(){
float r,s,l,c;
	printf("圆的半径为：");
	scanf("%f",&r);
	s=r*r*3.14;
	l=2*r;
	c=6.28*r;
	printf("该圆的直径为:%.2f，周长为:%.2f，面积为:%.2f",l,c,s);//.2仅限制小数部分 
}
