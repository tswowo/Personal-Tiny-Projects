#include<stdio.h>
int main(){
	printf("������һ��������");
	int a;
	scanf("%d",&a);
	switch(a){
		case 1:
		case 3:
		case 5:
		case 7:
		case 9:
			printf("�����������\n");
			break;
		default:
			printf("�������ż��\n");
		case 2:
			printf("�������ż��2\n");
	}
	return 0;
}
