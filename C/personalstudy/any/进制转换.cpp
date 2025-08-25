#include<stdio.h>
#include<ctype.h>
#include<string.h>

void change(char *num,int x,int n)
{
	while(x>0)
	{
		if(x%n>9)
		{
			*num=x%n-10+'A';
			num++;
		}
		else if(x%n<=9)
		{
			*num=x%n+'0';
			num++;
		}
		x/=n;
	}
	*num='\0';
}

int main()
{
	int x,n;
	scanf("%d%d",&x,&n);
	char str[100];
	change(str,x,n);
	int len=strlen(str);
	while(len>=0)
	{
		printf("%c",str[len]);
		len--;
	}
    return 0;
}
