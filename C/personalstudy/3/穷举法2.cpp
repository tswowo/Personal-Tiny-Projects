#include"stdio.h"
main(){
	int one,two,five,x;
	scanf("%d",&x);
	for(one=0;one<=x;one++){
		for(two=0;two<=x-one;two++){
			for(five=0;five<=x-one-2*two;five++){
				if(one+2*two+5*five==x)
					printf("%d元内，五角%d个，两角%d个，一角%d个\n",x,five,two,one);
			}
		}
	}
}
