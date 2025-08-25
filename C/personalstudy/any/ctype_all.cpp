#include<stdio.h>
#include<ctype.h>

int main()
{
	for(int i=0;i<=127;i++)
	{
		printf("%d:",i);
		//printf("%d",isalnum(i));//大写字母1	小写字母2 数字4 其余0 
		//printf("%d",isalpha(i));//大写字母1	小写字母2 其余0
		//printf("%d",iscntrl(i));//控制字符32	其余0
		//printf("%d",islower(i));//小写字母2	其余0 
		//printf("%d",isupper(i));//大写字母1	其余0
		//printf("%d",isdigit(i));//十进制数字1		其余0
		//printf("%d",isxdigit(i));//十六进制数字1		其余0
		//printf("%d",isgraph(i));//大写字母1	小写字母2 数字4 标点符号16 其余0 
		//printf("%d",isprint(i));//大写字母1	小写字母2 数字4 标点符号16 空格64 其余0 
		//printf("%d",ispunct(i));//标点符号16 
		//printf("%d",isspace(i));//难评 
		
		printf("\t%c\n",i);
	}
    return 0;
}
