#include<stdio.h>
//top指向栈顶的下一位 
int stack[15]={-1};//使用全局数组模拟栈,0为栈底 

int* top=stack+1,*bottom=stack;//栈顶，栈底

int clearstack(int a[]);//清空栈 
int StackEmpty(int a[]);//查看栈是否为空 
int StackLength(int a[]);//获取栈长 
int GetTop(int a[]);//获取栈顶 
int push(int a[],int num);//入栈 
int pop(int a[]);//出栈
int puts(int a[]);//测试() 

int main()
{
	push(stack,114514);
	push(stack,1919810);
	push(stack,19);
	push(stack,89);
	push(stack,64);
	push(stack,155);
	push(stack,4520);
	push(stack,7712);
	push(stack,2024);
	push(stack,211);
	push(stack,602);
	push(stack,2006);
	push(stack,2024);
	push(stack,02);
	push(stack,12);
	puts(stack);
	printf("Stack_Empty is %d\n",StackEmpty(stack));
	printf("the top is %d\n",GetTop(stack));
	printf("the Length is %d\n",StackLength(stack));
	pop(stack);
	pop(stack);
	pop(stack);
	puts(stack);
	printf("Stack_Empty is %d\n",StackEmpty(stack));
	printf("the top is %d\n",GetTop(stack));
	printf("the Length is %d\n",StackLength(stack));
	puts(stack);
	printf("Stack_Empty is %d",StackEmpty(stack));
	printf("the top is %d\n",GetTop(stack));
	printf("the Length is %d\n",StackLength(stack));
}



int puts(int a[])
{
	for(int i=0;i<15;i++)printf("a[%d]=%d\n",i,a[i]);
	return 0;
}



int clearstack(int a[])//清空栈 
{
	while(top!=bottom)
		*(--top)=0;
	return 0;
}

int StackEmpty(int a[])//栈是否为空 
{
	if(top-1==bottom)return 1;//栈为空
	else return 0;//栈不为空 
}

int StackLength(int a[])//获取栈的长度 
{
	return top-bottom-1;
}

int GetTop(int a[])//获取栈顶 
{
	return *(top-1);
}

int push(int a[],int num)//入栈一个元素，成功返回1，失败返回-1 
{
	if(top<=bottom+14)
	{
		*(top++)=num;
		return 1;
	}
	else return -1;
}

int pop(int a[])//出栈一个元素，成功返回1，失败返回-1 
{
	if(top!=bottom)
	{
		*(--top)=0;
		return 1;
	}
	else return -1;
} 
