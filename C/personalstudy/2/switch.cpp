#include<stdio.h>
int main(){
	printf("������һ��������");
	int a;
	scanf("%d",&a);
	switch(a){
		case 5:
			printf("���������5");
			break;
		case 4:
			printf("���������4");
			break;
		case 3:
			printf("���������3");
			break;
		case 2:
			printf("���������2");
			break;
		case 1:
			printf("���������1"); 
			break;
		default:
			printf("�����������1��2��3��4��5");
	}
}
