#include<stdio.h>
int main(){
	int i,k;
	printf("�����볤�ȣ�");
	scanf("%d",&i);
	fflush(stdin);
	int num[i];
	printf("�������������֣�");
	for (k=0;k<i;k++){
		printf("\n��%d������:",k+1);
		scanf("%d",&num[k]);
		fflush(stdin);
	}
	
	//���������� 
	/*int *a;
	a=&num[0];//����дa=&numЧ����һ����,ָ�������һ��������������ָ���������� 
	for(k=0;k<i;k++){
		printf("\n%d",*a);
		a+=1;
	}*/
	
	//����������
	for(int *a=num;a<(num+3);a++){
		printf("\n%d",*a);
	}
}
