#include<stdio.h>
int main(){
	int a[24],i;//定义输入数组a 
	for(i=0;i<=25;i++){
		a[i]=i;
	}
	
	int b[4][4],k,l;//初始化二维数组B 
	for(k=0;k<5;k++){
		for(l=0;l<5;l++){
			b[k][l]=0;
		}
	}
	
	i=0;
	for(k=0;k<5;k++){//以数组a填充数组b，但左下角均为0 
		for(l=0;l<5;l++){
			if(l>k+1){
				b[k][l]=a[i];
				i++;
			}
		}
	}
	
	for(k=0;k<5;k++){
		for(l=0;l<5;l++){
			printf("%d\t",b[k][l]);
		}
		printf("\n");
	}
}
