#include<stdio.h>
int main(){
	/*int a[2][2];
	a[0][0]=1;
	a[1][0]=1;
	a[1][1]=a[0][0]+a[0][1];
	printf("%d",a[1][1]);*/



	long long int i,k,a[15][15];
	a[0][0]=1;
	a[1][0]=1;
	a[1][1]=1;
	printf("%lld\n%lld\t%lld\n",a[0][0],a[1][0],a[1][1]);
	for(i=2;i<=14;i++){
		a[i][0]=1;
		a[i][i]=1;
		printf("%lld\t",a[i][0]);
		for(k=1;k<i;k++){
			a[i][k]=a[i-1][k]+a[i][k-1];
			printf("%lld\t",a[i][k]);
		}
		printf("%lld\n",a[i][i]);
	}
}
