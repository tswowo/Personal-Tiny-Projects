#include<stdio.h>
int main(){
	printf("ÇëÊäÈëÄ§·½½×Êı£º");
	int n,i=0,k=0,N;
	scanf("%d",&n);
	printf("\n");
	int a[n][n];
	
	for(i=0;i<n;i++){
		for(k=0;k<n;k++){
			a[i][k]=0;
		}
	}
		i=0;
		k=0;
	for(N=1;N<=(n)*(n);N++){
		a[i][k]=N;
		i+=1;
		k+=1;
		if(i==n){
			i=0;
		}
		if(k==n){
			k=0;
		}
		while(a[i][k]!=0){
			k++;
		}
		
	}
	
	
	
	
	
	for(i=0;i<n;i++){
		for(k=0;k<n;k++){
			printf("%d\t",a[i][k]);
		}
	printf("\n");
	}
}

