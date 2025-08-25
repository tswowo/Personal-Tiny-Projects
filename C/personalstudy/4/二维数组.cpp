#include"stdio.h"
int main(){
	int a[3][5];
	int i,k;
	for(i=0;i<3;i++){
		for(k=0;k<5;k++){
			a[i][k]=i+k;
			printf("%4d\n",a[i][k]);
		}
	}
}
