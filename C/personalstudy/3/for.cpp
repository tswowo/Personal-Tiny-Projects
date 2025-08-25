#include"stdio.h"
main()
{
	int a;
	for(a=0;a<=100;a++)//先执行表达式1，2，再执行语句块，最后执行表达式3 
	{
		printf("%d\n",a);
	}	
}
