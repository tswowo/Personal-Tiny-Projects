#include<stdio.h>
int main()
{
	char str1[100],str2[100],ch;
	int i,k;
	gets(str1);
	ch=getchar();
	for(i=0;str1[i]!='\0';i++)
	{
		k=0;
		while(1)
		{
			if(str1[i]!=ch)
			{
				str2[k]=str1[i];
				k++;
			}
			if(str1[i]=='\0')break;
		}
	}
	puts(str2);
	return 0;
} 
