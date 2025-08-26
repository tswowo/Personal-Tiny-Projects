#include<stdio.h>
int jiecheng(int x){
	int result=1,i;
	for(i=1;i<=x;i++){
		result*=i;
	}
	return result;
}

int sum(int a,int b){
	int sum=jiecheng(a)+jiecheng(b);
	return sum;
}

int main(){
	int su,x,y;
	scanf("%d%d",&x,&y);
	su=sum(x,y);
	printf("%d",su);
	return 0;
}
