#include<stdio.h>
int main()
{
	FILE* p;
	p=fopen("test_no_dottxt","wb");
	fputs("123456",p);
	fclose(p);
	p=fopen("test_no_dottxt","rb");
	char str[100];
	fscanf(p,"%s",str);
	puts(str);
	return 0;
}
