#include<stdio.h>
int main()
{
	FILE* p;
	p=fopen("two.txt","wb");
	fputs("123456",p);
	fclose(p);
	p=fopen("two.txt","rb");
	char str[100];
	fscanf(p,"%s",str);
	puts(str);
	return 0;
}
