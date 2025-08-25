#include <stdio.h> 
main(){
	int i;
	i=1;
	while(i<10){
	    i++;
		if(i%3==0)
		    continue;
		printf("%d   ",i);	
	}
	printf("\n");
}
