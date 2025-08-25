#include<stdio.h>
int main()
{
	//int fscanf (FILE * fp, char format, args, …);
	//从fp指定文件中按format指定格式将数据送到args中
	//返回已输入数据的个数 
	FILE *p;
	p=fopen("test_fscanf.txt","w");
	char str[100];
	
	fputs("Die\nDer Des",p);
	fclose(p);
	
	p=fopen("test_fscanf.txt","r");
	while(fscanf(p,"%s",str)>0)
		puts(str);
	return 0;
}
