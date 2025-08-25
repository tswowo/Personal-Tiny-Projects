#include"stdio.h"//scanf后要加&以a添加地址 
main(){
	int aaa,bbb,ccc;
	printf("请输入两个整数：",aaa,bbb);
	scanf("%d%d",&aaa,&bbb);
	printf("aaa=%d\tbbb=%d\n请输入第三个整数：",aaa,bbb);
	fflush(stdin);
	scanf("%d",&ccc);
	printf("ccc=%d",ccc);
	/*用户输入的数据先存入系统的输入缓存区，待需要数据时，
	如果缓存区不空，则从缓存区直接读取，如果缓存区空，则等待用户输入。*/
	//可以在每次读取前使用fflush(stdin)清空缓存区函数 
	
	
	
	
	
	
	
	
	/*
	int aa,bb,cc;
	scanf("a%2db%2dc%2d",&aa,&bb,&cc);//如果格式控制串中，有非格式控制内容，
	printf("aa=%dbb=%dcc=%d",aa,bb,cc);//那么在输入时必须依次对应，否则会导致输入失败
	*/
	
	/*int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("a=%db=%dc=%d",a,b,c);//可以使用1回车2回车3回车输入，也可以输入1 2 3，
								//甚至1,2,3\1.2.3貌似相同符号隔开即可 
*/
	
	
	/*int inputyear,age;
	char a1;
	printf("请输入你的出生年份:");
	scanf("%d",&inputyear);
	age=2024-inputyear;
	printf("你的年龄为:%d",age);*/
}
