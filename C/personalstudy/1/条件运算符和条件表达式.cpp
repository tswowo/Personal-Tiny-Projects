#include<stdio.h>
main(){
	int a,b,c;
	a=10;
	b=3;
	c=3>2?a+3:10;//不改变a的值，因3>2成立，c=a+3的值 
	printf("%d\n",a);
	printf("%d\n",c);
	c=3>2?a=a+3:10;//改变a的值为a+3，因3>2成立，c=a+3的值 
	printf("%d\n",a);
	printf("%d\n",c);
}
