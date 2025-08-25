#include<stdio.h>
int main(){
	int a=1,b=1,c,d=1,e;
	scanf("%d",&c);
	while(d<=c){
		printf("%d\n",a);
		d++;
		e=b;
		b+=a;
		a=e;
	}
}
