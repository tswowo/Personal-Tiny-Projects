#include<stdio.h>
int main()
{
	//stdio.h�ж����˱���ΪFILE�Ľṹ��ָ���������
	//�Լ�����ļ���д��������
	FILE *p;//����ָ��һ�����ļ����ļ���Ϣ����ͨ���ļ���Ϣ������Ϣ���� ���ʸ��ļ�
	p=fopen("test_open.txt","w");//"w"ֻд��ָ���ļ�������ʱ���������ļ� 
	
	fputs("Hello World\n",p);//fputs���ļ���ͷ���ļ�д���� 
	fputs("Hello Shopping",p);
	
	fclose(p);//�ر��ļ���ȷ���ļ���ȫ
	//���û�йر��ļ�������ִ����Ϻ��ļ�Ҳ���Զ��ر� 
	p=NULL;
	return 0;	
}
