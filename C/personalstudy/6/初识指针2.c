#include<stdio.h>
int main(){
	int a=10;
	int *b;
	b=&a;
	printf("%d\n",*b);
	
	int c=10;
	int *d=&c;
	printf("%d\n",*d);
}
