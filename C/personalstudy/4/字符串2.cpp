#include <stdio.h>
#include <string.h>
main()
{
	char s1[50]="���,",s2[50]="��Ҫ��ѧ��",s3[50]="123";
	printf("�ַ�����������Ϊ��%d,%d,%d\n",strlen(s1),strlen(s2),strlen(s3));
	strcat(s1,s2);
	strcat(s1,s3);
	puts(s1);
	printf("%d",strcmp(s1,s2));//С�� 
	printf("%d",strcmp(s1,s1));//���� 
	printf("%d",strcmp(s1,s3));//���� 
}
