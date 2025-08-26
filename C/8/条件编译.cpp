#include<stdio.h>
int main()
{
	//1
//	#ifdef如果定义了宏 #ifndef如果没有定义宏 
	#ifndef DEBUG//也可以用嵌套 
		printf("NO DEBUG\n");
		#define DEBUG
		#ifdef DEBUG
			printf("DEBUG has difined\n");
		#endif
	#endif//每个ifdef||ifndef后必须要有endif配对，作用类似于}，条件编译结束标记
	
	//2
	#define isRight 0
	#if isRight==1
		printf("Right is Right\n");
	#elif isRight==0
		printf("Right is Worry\n");
	#else
		printf("Unknown\n");
	#endif//同样要以endif结尾 
	
	//3
	for(int i=0;i<10;i++)
	{
		//像这样将变量放入预编译模块的方式，其值在编译过程中就得到确定 
		#if isRight==i
			printf("%d\n",i);
		#endif
	}
}
