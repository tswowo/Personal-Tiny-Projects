#include<stdio.h>
//topָ��ջ������һλ 
int stack[15]={-1};//ʹ��ȫ������ģ��ջ,0Ϊջ�� 

int* top=stack+1,*bottom=stack;//ջ����ջ��

int clearstack(int a[]);//���ջ 
int StackEmpty(int a[]);//�鿴ջ�Ƿ�Ϊ�� 
int StackLength(int a[]);//��ȡջ�� 
int GetTop(int a[]);//��ȡջ�� 
int push(int a[],int num);//��ջ 
int pop(int a[]);//��ջ
int puts(int a[]);//����() 

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



int clearstack(int a[])//���ջ 
{
	while(top!=bottom)
		*(--top)=0;
	return 0;
}

int StackEmpty(int a[])//ջ�Ƿ�Ϊ�� 
{
	if(top-1==bottom)return 1;//ջΪ��
	else return 0;//ջ��Ϊ�� 
}

int StackLength(int a[])//��ȡջ�ĳ��� 
{
	return top-bottom-1;
}

int GetTop(int a[])//��ȡջ�� 
{
	return *(top-1);
}

int push(int a[],int num)//��ջһ��Ԫ�أ��ɹ�����1��ʧ�ܷ���-1 
{
	if(top<=bottom+14)
	{
		*(top++)=num;
		return 1;
	}
	else return -1;
}

int pop(int a[])//��ջһ��Ԫ�أ��ɹ�����1��ʧ�ܷ���-1 
{
	if(top!=bottom)
	{
		*(--top)=0;
		return 1;
	}
	else return -1;
} 
