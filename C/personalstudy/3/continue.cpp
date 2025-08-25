#include"stdio.h"
main(){
	int a=1,i=0;
	while(a<=100){
		a++;
		if(a%3==0||a%7==0){
			continue;}; 
		i+=a;
	}
	printf("%d",i);
}
