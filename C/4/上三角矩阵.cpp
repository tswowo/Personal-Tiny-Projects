#include<stdio.h>
int main(){
	int a[24],i;//������������a 
	for(i=0;i<=25;i++){
		a[i]=i;
	}
	
	int b[4][4],k,l;//��ʼ����ά����B 
	for(k=0;k<5;k++){
		for(l=0;l<5;l++){
			b[k][l]=0;
		}
	}
	
	i=0;
	for(k=0;k<5;k++){//������a�������b�������½Ǿ�Ϊ0 
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
