#include<stdio.h>

void A(int b[]){
	if(b[0]<=2){
		b[0]++;
		A(b);
	}
}

int main(){
	int a[1];
	a[0]=0;
	A(a);
	printf("%d",a[0]);
	return 0;
}
