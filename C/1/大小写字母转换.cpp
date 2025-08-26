#include<stdio.h>
main(){
	char c1;
	printf("请输入一个大写字母：");
	scanf("%c",&c1);
	c1+=32;
	printf("\n转换后的小写字母为：%c\n",c1);

	
	
	
	
	
	
/*char c;
c='a';printf("%c,%d\n",c,c);		//原理是这样的，变量编码相差32，a97,A65 ，小写比大写多32 
c='z';printf("%c,%d\n",c,c);		//小写字母为97-122，大写字母为65-90 
c='A';printf("%c,%d\n",c,c);
c='Z';printf("%c,%d\n",c,c);*/
}
