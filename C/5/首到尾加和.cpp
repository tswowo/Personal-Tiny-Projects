#include<stdio.h>
int sum(int a,int b){
	int i,sum;
	for(sum=0;a<=b;a++){
		sum+=a;
	}
	return sum;
}

int main(void){
	int begin,end,r;
	scanf("%d%d",&begin,&end);
	r=sum(begin,end);
	printf("%d",r);
}
