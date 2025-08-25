#include"stdio.h"
main(){
	int n,a;
	scanf("%d",&n);
	while(n>9){
		printf("%d",n%10);
		n/=10;
	}
	printf("%d",n);
}
