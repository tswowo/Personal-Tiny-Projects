#include<stdio.h>
//����Ԫ�����������ȼ��ڱ�������δ��벢�����޸���������� 

int f(int b){
	int num;
	printf("\n%�޸�Ϊ��\n");
	scanf("%d",&num);
	b=num;
}

int main(){
	int i,k;
	int a[4];
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
		fflush(stdin);
	} 
	printf("\n%������Ҫ�޸ĵ����ֵ�λ�ã�\n");
	scanf("%d",&i);
	i--;
	f(a[i]);
	printf("�����");
	for(k=0;k<5;k++){
		printf("%d\t",a[k]);
	} 
}
