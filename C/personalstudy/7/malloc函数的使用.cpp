#include<stdio.h>
#include<string.h>
#include<stdlib.h>//包含了malloc等内存相关函数 
int main()
{
	int *x;
	x=(int*)malloc(sizeof(int));
	//malloc的返回类型是指针，但指针有类型区分，所以要进行强制转换 
	*x=1;
	printf("%d\n",*x);
	
	//不用的空间可以使用free()释放
	free(x); 
	
	int *p,i;//malloc分配数组空间如是说 
	p=(int *)malloc(sizeof(int)*10);
	for(i=0;i<10;i++)
		p[i]=i*i;
	for(i=0;i<10;i++)
		printf("%5d",p[i]);

}
