#include <stdio.h>//����Ԫ�����������ȼ��ڱ���
int ff(int k){
	k=9;
	printf("������k��ֵΪ%d\n",k);
	return k;
} 
main(){
	int a[]={1,2,3,4,5};
	ff(a[2]);
	printf("��������a[2]��ֵΪ%d\n",a[2]);
	return 0;
}
#include <stdio.h>//�����������������ݵ�������ĵ�ַ
int ff(int k[]){
	k[2]=9;
	printf("������k[2]��ֵΪ%d\n",k[2]);
	return k[2];
} 
main(){
	int a[]={1,2,3,4,5};
	ff(a);
	printf("��������a[2]��ֵΪ%d\n",a[2]);
	return 0;
}
