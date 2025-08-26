#include"stdio.h"
main(){//100 5 3 1
	int a,b,c,last,x;
	scanf("%d",&x);
	for(a=0;a<=x/5;a++){
		last=100-5*a;
		for(b=0;b<=last;b++){
			c=last-3*b;
			if(c>=0)
			printf("%d元内，5元有%d张，3元有%d张，1元有%d张\n",x,1a,b,c);
			
		}
	}
}
