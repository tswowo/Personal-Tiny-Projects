#include <stdio.h>
void f(int a){
	printf("�����������ݹ�����ֵΪ%d\n",a);
	a=36;
	printf("���������ı���ֵΪ%d\n",a);
}
main(){
	int k;
	k=99;
	printf("���ú���ǰ������ֵΪ%d\n",k);
	f(k);
	printf("���ú����������ֵΪ%d\n",k);
}
