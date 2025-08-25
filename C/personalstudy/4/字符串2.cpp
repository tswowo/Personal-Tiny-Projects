#include <stdio.h>
#include <string.h>
main()
{
	char s1[50]="你好,",s2[50]="我要自学网",s3[50]="123";
	printf("字符串长度依次为：%d,%d,%d\n",strlen(s1),strlen(s2),strlen(s3));
	strcat(s1,s2);
	strcat(s1,s3);
	puts(s1);
	printf("%d",strcmp(s1,s2));//小于 
	printf("%d",strcmp(s1,s1));//等于 
	printf("%d",strcmp(s1,s3));//大于 
}
