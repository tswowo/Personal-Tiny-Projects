#include<stdio.h>
main()
{
	char ss[]="csdxpsl";//�������Ϊ��\0��,������ϵͳĬ�ϸ������Ϊ���� 
	ss[4]='\0';
	puts(ss);
	
	
	/* getchar putchar;
		gets	puts;
		%c %s;
		\0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	char a1,a2[10],a3[10];
	//�ַ������������ 
	/*
	a1=getchar();
	putchar(a1);
	*/
	
	//�ַ��������������1 
	/*
	scanf("%s%s",&a2,&a3);
	printf("%s,%s",a2,a3);
	*/
	
	//�ַ��������������2
	/*
	gets(a2);
	gets(a3);//puts(a2);
	printf("%s,%s",a2,a3);
	*/
	
   /*
   char s1[]="abcde";
   char s2[]={'a','b','c','d','e'};
   printf("�ַ�������Ϊ��%d,�ַ�����ռ�Ϊ��%d\n",sizeof(s1),sizeof(s2));
   */
}
