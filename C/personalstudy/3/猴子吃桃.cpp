#include"stdio.h"
main(){
	int day,pp=1;
	scanf("%d",&day);
	for(;day>=1;day--){
		pp+=1;
		pp*=2;
		printf("day=%d\tpp=%d\n",day,pp);
	}
	printf("\n%d",pp);
}
