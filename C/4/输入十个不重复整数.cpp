#include<stdio.h>
int main(){
	int a[9],c,k,i;
	for(k=0;k<=i;k++){
		a[k]=0;
	}
	printf("����ʮ����ͬ��������");
	for(i=0;i<10;){
		scanf("%d",&c);
		//����ظ����� 
		for(k=0;k<9;k++){
			if(c==a[k])
				break;//������ظ����֣���ǰ����ѭ����kС��9 
		}
		
		if(k==9){//���û���ظ����֣�kӦ�õ���i+1 
			a[i]=c;
			i++;
		}
		else if(k<9)
			printf("�������ظ����롣\n");
			fflush(stdin); 
	}
	for(k=0;k<i;k++){//������� 
		printf("%d",a[k]);
	}
}
