#include"stdio.h"//scanf��Ҫ��&��a��ӵ�ַ 
main(){
	int aaa,bbb,ccc;
	printf("����������������",aaa,bbb);
	scanf("%d%d",&aaa,&bbb);
	printf("aaa=%d\tbbb=%d\n�����������������",aaa,bbb);
	fflush(stdin);
	scanf("%d",&ccc);
	printf("ccc=%d",ccc);
	/*�û�����������ȴ���ϵͳ�����뻺����������Ҫ����ʱ��
	������������գ���ӻ�����ֱ�Ӷ�ȡ������������գ���ȴ��û����롣*/
	//������ÿ�ζ�ȡǰʹ��fflush(stdin)��ջ��������� 
	
	
	
	
	
	
	
	
	/*
	int aa,bb,cc;
	scanf("a%2db%2dc%2d",&aa,&bb,&cc);//�����ʽ���ƴ��У��зǸ�ʽ�������ݣ�
	printf("aa=%dbb=%dcc=%d",aa,bb,cc);//��ô������ʱ�������ζ�Ӧ������ᵼ������ʧ��
	*/
	
	/*int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("a=%db=%dc=%d",a,b,c);//����ʹ��1�س�2�س�3�س����룬Ҳ��������1 2 3��
								//����1,2,3\1.2.3ò����ͬ���Ÿ������� 
*/
	
	
	/*int inputyear,age;
	char a1;
	printf("��������ĳ������:");
	scanf("%d",&inputyear);
	age=2024-inputyear;
	printf("�������Ϊ:%d",age);*/
}
