#include<stdio.h>
#include<ctype.h>

int main()
{
	for(int i=0;i<=127;i++)
	{
		printf("%d:",i);
		//printf("%d",isalnum(i));//��д��ĸ1	Сд��ĸ2 ����4 ����0 
		//printf("%d",isalpha(i));//��д��ĸ1	Сд��ĸ2 ����0
		//printf("%d",iscntrl(i));//�����ַ�32	����0
		//printf("%d",islower(i));//Сд��ĸ2	����0 
		//printf("%d",isupper(i));//��д��ĸ1	����0
		//printf("%d",isdigit(i));//ʮ��������1		����0
		//printf("%d",isxdigit(i));//ʮ����������1		����0
		//printf("%d",isgraph(i));//��д��ĸ1	Сд��ĸ2 ����4 ������16 ����0 
		//printf("%d",isprint(i));//��д��ĸ1	Сд��ĸ2 ����4 ������16 �ո�64 ����0 
		//printf("%d",ispunct(i));//������16 
		//printf("%d",isspace(i));//���� 
		
		printf("\t%c\n",i);
	}
    return 0;
}
