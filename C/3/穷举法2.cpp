#include"stdio.h"
main(){
	int one,two,five,x;
	scanf("%d",&x);
	for(one=0;one<=x;one++){
		for(two=0;two<=x-one;two++){
			for(five=0;five<=x-one-2*two;five++){
				if(one+2*two+5*five==x)
					printf("%dԪ�ڣ����%d��������%d����һ��%d��\n",x,five,two,one);
			}
		}
	}
}
