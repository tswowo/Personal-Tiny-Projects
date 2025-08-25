#include<stdio.h>
char *strcpy1(char*a,char*b);
int strlen1(char*p);
char *strcat1(char*a,char*b);
int strcmp1(char*a,char*b);

int main()
{
	char a[10],b[10],c[10];
	gets(a);
	gets(b);
	printf("%d",strcmp1(a,b));
	return 0;
}

int strlen1(char *p)
{
	int i;
	for(i=0;*(p+i)!='\0';i++);
	return i;
}

char *strcpy1(char*a,char*b)
{
	char* c=a;
	for(;*b!='\0';a++,b++)
		*a=*b;
	return c;
}


char *strcat1(char*a,char*b)
{
	char*c=a;
	while(*a!='\0')a++;
	while(*b!='\0')
	{
		*a=*b;
		a++;
		b++;
	}
	return c;
}

int strcmp1(char*a,char*b)
{
	while(*a==*b)
	{
		if(*a=='\0')return 0;
		a++;
		b++;
	}
	if(*a>*b)return 1;
	else if(*a<*b)return -1;
}
