#include<stdio.h>
main(){
	char a;
	a='b';
	printf("%d",a);
	printf("%c",a);
	printf("�ַ��������ֽ���Ϊ%d\n",sizeof(a));
	printf("�ַ��������ֽ���Ϊ%c\n",sizeof(a));
	a=a+1;
	printf("%d",a);
	printf("%c",a);
	int b;
	b=1;
	printf("%d\n",b);
	printf("%c\n",b);
	printf("���ͱ������ֽ���Ϊ%d\n",sizeof(b));
	printf("���ͱ������ֽ���Ϊ%c\n",sizeof(b));
	printf("%d\n",sizeof(int));
	printf("%d\n",sizeof(long));
	printf("%d\n",sizeof(char));
	printf("%d\n",sizeof(1));
}
