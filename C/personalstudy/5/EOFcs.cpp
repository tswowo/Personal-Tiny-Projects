#include<stdio.h>//ps:��ô���Ĵ��벻����д�� 
int main(){
	int a,b,c,m;
	while(scanf("%d %d %d",&a,&b,&c)!=EOF){
		if(a>b){
			m=a;
			a=b;
			b=c;
		}
		if(a>c){
			m=c;
			c=a;
			a=m;
		}
		if(b>c){
			m=c;
			c=b;
			b=m;
		}
		printf("%d%d%d",a,b,c);
	}
} 
