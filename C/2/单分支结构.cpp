#include<stdio.h>
int main(){
	int num;
	scanf("%d",&num);
	if(!((num%5==0)|(num%2==0)))
		printf("none");
	if((num%5==0)|(num%2==0))
		printf("%d",num);
	
	
	
	/*
	int a,b,c;
	printf("请输入三个整数\n");
	scanf("%d%d%d",&a,&b,&c);
	if(a%2==0)a++;
	if(b%2==0)
	b++;
	if(c%2==0)
		c++;
	printf("a=%d\tb=%d\tc=%d",a,b,c);*/
}
