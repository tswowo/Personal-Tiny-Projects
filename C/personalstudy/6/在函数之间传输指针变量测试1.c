#include<stdio.h>
void ff(int *a,int *b){
	int f;
	if(*a>*b){
		f=a;
		a=b;
		b=f;
	}
	printf("%d,%d",*a,*b);
}

int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	ff(&m,&n);
	return 0;
}
