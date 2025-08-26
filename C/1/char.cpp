#include<stdio.h>
main(){
	char a;
	a='b';
	printf("%d",a);
	printf("%c",a);
	printf("字符变量的字节数为%d\n",sizeof(a));
	printf("字符变量的字节数为%c\n",sizeof(a));
	a=a+1;
	printf("%d",a);
	printf("%c",a);
	int b;
	b=1;
	printf("%d\n",b);
	printf("%c\n",b);
	printf("整型变量的字节数为%d\n",sizeof(b));
	printf("整型变量的字节数为%c\n",sizeof(b));
	printf("%d\n",sizeof(int));
	printf("%d\n",sizeof(long));
	printf("%d\n",sizeof(char));
	printf("%d\n",sizeof(1));
}
