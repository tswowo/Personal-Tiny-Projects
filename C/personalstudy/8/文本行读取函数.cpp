#include<stdio.h>
int main()
{//fgetc���ı��ļ���ȡ����	fgets���ı��ж�ȡ���� 
	char str[100];
	//fgets
	FILE* p;
	p=fopen("fgets_read.txt","w");
	fputs("HDMIDPP_VGA",p);
	fclose(p);
	
	p=fopen("fgets_read.txt","r");
	/*char c;
	while((c=fgetc(p))!=EOF)
		putchar(c);*/
	
	int x;
	scanf("%d",&x);
	fgets(str,x+1,p);//char * fgets (char * buf, int n, FILE * fp);
					//��fp�ж�ȡn-1���ַ����浽buf�� 
	puts(str);
	
	fgets(str,x+1,p);
	puts(str);
	
	return 0;
}
