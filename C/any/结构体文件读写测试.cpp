#include<stdio.h>
#include<string.h>

typedef struct places{
	char name[20];
	int age;
}places;

int main()
{
	int n;
	scanf("%d",&n);
	places pp[n];
	//���벿�� 
	for(int i=0;i<n;i++)
		scanf("%s%d",pp[i].name,&pp[i].age);
	//д�벿�� 
	FILE *p;
	p=fopen("�ṹ���ļ���д����.txt","w");
	fwrite(pp,2,sizeof(places),p);//�����-�ṹ�����������-�����ṹ��Ĵ�С-������
	fclose(p);
	//��ȡ���� 
	places qq[n];
	FILE *q;
	q=fopen("�ṹ���ļ���д����.txt","r");
	fread(qq,2,sizeof(places),q);//�����-�ṹ�����������-�����ṹ��Ĵ�С-������ 
	//������� 
	for(int i=0;i<n;i++)
	{
		printf("%s %d\n",qq[i].name,qq[i].age);
	}
	return 0;
}
