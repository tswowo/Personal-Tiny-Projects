#include<stdio.h>

int cc(int x){
	int reason;
	if(x==0||x==1)reason=1;
	else reason=cc(x-1)*x;
	return reason;
}

int main(){
	int a,b;
	scanf("%d",&a);
	b=cc(a);
	printf("%d",b);
}

