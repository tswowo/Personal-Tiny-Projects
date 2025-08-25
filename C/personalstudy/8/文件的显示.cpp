#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *p;
	char str[10];
	gets(str);
	
	p=fopen("test_read.txt","w");
	fputs(str,p);
	fclose(p);
	
	p=fopen("test_read.txt","r");
	
	char c;
	printf("%p\n",p);
	while((c=fgetc(p))!=EOF)
	{
		putchar(c);
		printf("?%p\n",p);
	}
	
	printf("--\n--\n");
	
	p=fopen("test_read.txt","r");
	while((c=fgetc(p))!=EOF)
	{
		putchar(c);
		printf(":%p\n",p);
	}
	
	fclose(p);
	return 0;
}
