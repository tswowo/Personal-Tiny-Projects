#include<stdio.h>
main()
{
	char ss[]="csdxpsl";//结束标记为“\0”,可以由系统默认赋予或人为赋予 
	ss[4]='\0';
	puts(ss);
	
	
	/* getchar putchar;
		gets	puts;
		%c %s;
		\0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	char a1,a2[10],a3[10];
	//字符的输入与输出 
	/*
	a1=getchar();
	putchar(a1);
	*/
	
	//字符串的输入与输出1 
	/*
	scanf("%s%s",&a2,&a3);
	printf("%s,%s",a2,a3);
	*/
	
	//字符串的输入与输出2
	/*
	gets(a2);
	gets(a3);//puts(a2);
	printf("%s,%s",a2,a3);
	*/
	
   /*
   char s1[]="abcde";
   char s2[]={'a','b','c','d','e'};
   printf("字符串长度为：%d,字符数组空间为：%d\n",sizeof(s1),sizeof(s2));
   */
}
