#include<stdio.h>
int main(){
	int i,n;
	//���ַ����鴢����������� 
	printf("��������Ҫ���������������");
	scanf("%d",&i);
	int a[i-1];
	fflush(stdin);
	printf("\n��������Ҫ��������֣�");
	for(n=0;n<i;n++){
		scanf("%d",&a[n]);
		fflush(stdin);
	}
	//�������
	int f;
	for(f=i-1;f>=0;f--){
		printf("%d",a[f]);
	}
}
