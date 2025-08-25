#include"stdio.h"
main(){
	int a=0,s=0;
	while(a<=100&&s<=1000){
		s+=a;
		a++;
	}
	s-=a;
	printf("%d",s);
}
