#include<stdio.h>
//�����������������ݵ�������ĵ�ַ�����Ե��ú������޸�ʵ�� 
//ʵ�������β������ʵ������Ϊͬһ���飬��ͬӵ��һ���ڴ�ռ䡣 
//ʵ�����β�����Ϊα���飬��ָ�룬�ǵ�ַ������
int f(int b[]){
	int i,num;
	printf("\n%������Ҫ�޸ĵ����ֵ�λ�ã�\n");
	scanf("%d",&i);
	i--;
	printf("\n%�޸�Ϊ��\n");
	scanf("%d",&num);
	b[i]=num;
}

int main(){
	int i,k;
	int a[4];
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
		fflush(stdin);
	} 
	f(a);
	printf("�����");
	for(k=0;k<5;k++){
		printf("%d\t",a[k]);
	} 
}
