#include<stdio.h>
int sun(int a[],int b){
	int sun=0,i;
	for(i=0;i<=b;i++){
		sun+=a[i];
	}
	return sun;
}

int main(){
	int i,k,sum;
	printf("���������鳤��:");
	scanf("%d",&i);
	int a[i-1];
	fflush(stdin);
	printf("������%d����:",i);
	for(k=0;k<i;k++){
		scanf("%d",&a[k]);
		fflush(stdin);
	}
	sum=sun(a,i-1);
	printf("��ͽ��Ϊ��%d",sum);
}
