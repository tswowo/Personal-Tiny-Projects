#include<stdio.h>
int main(){
	int i,n,f,c;//���ַ����鴢����������� 
	printf("��������Ҫ���������������");
	scanf("%d",&i);
	int a[i];
	fflush(stdin);
	printf("\n��������Ҫ��������֣�");
	for(n=0;n<i;n++){
		scanf("%d",&a[n]);
		fflush(stdin);
	}
	//��ʼ���� 
	for(n=0;n<(i-1);n++){
		for(f=0;f<(i-1);f++){
			if(a[f]>a[f+1]){
				c=a[f];
				a[f]=a[f+1];
				a[f+1]=c;
			}
		}
	}
	
	
	for(n=0;n<i;n++){
		printf("%d\t",a[n]);
	}
	return 0;
}
