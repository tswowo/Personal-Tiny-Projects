#include<stdio.h>
int sb[2](void){
	int x[2];
	x=[1,2,3];
	return x;
}
int main(){
	int a[2]=sb();
	int i;
	for(i=0;i<3;i++){
		printf("%d",a[i]);
	}
}
