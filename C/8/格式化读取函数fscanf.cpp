#include<stdio.h>
int main()
{
	//int fscanf (FILE * fp, char format, args, ��);
	//��fpָ���ļ��а�formatָ����ʽ�������͵�args��
	//�������������ݵĸ��� 
	FILE *p;
	p=fopen("test_fscanf.txt","w");
	char str[100];
	
	fputs("Die\nDer Des",p);
	fclose(p);
	
	p=fopen("test_fscanf.txt","r");
	while(fscanf(p,"%s",str)>0)
		puts(str);
	return 0;
}
