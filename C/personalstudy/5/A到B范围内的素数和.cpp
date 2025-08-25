#include<stdio.h>
int ss(int a){
	if(a==0||a==1||a==2){
		return 0;
	}
	int k=2;
	for(;k<a;k++){
		if(a%k==0)break;
	}
	if(k==a) return 0;
	else return 1;
}

int main(){
	int a,b,sum=0;
	scanf("%d%d",&a,&b);
	for(;a<=b;a++){
		if(ss(a)==0){
			sum+=a;
		}
	}
	printf("%d",sum);
}
