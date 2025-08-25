#include<stdio.h>
int main()
{//fgetc是文本文件读取函数	fgets是文本行读取函数 
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
					//从fp中读取n-1个字符储存到buf中 
	puts(str);
	
	fgets(str,x+1,p);
	puts(str);
	
	return 0;
}
