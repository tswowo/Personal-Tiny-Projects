#include<stdio.h>//ps:这么笨的代码不是我写的 
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
