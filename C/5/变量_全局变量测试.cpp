#include<stdio.h>
/*2.ȫ�ֱ���

 �ں���֮�ⶨ��ı�����Ϊȫ�ֱ�����Ҳ��Ϊ�ⲿ��������������Ϊ�Ӷ��������λ�ÿ�ʼ����Դ�ļ�������

˵����

 ����1����Ϊ����ֻ�ܷ���һ������ֵ����˿���ͨ��ʹ��ȫ�ֱ�����ʵ��һ�������ı���ֵ�󣬻��ܱ������������á�

������2��ȫ�ֱ����ڳ���ִ�����������ж�ռ�ô洢��Ԫ��ʹ��̫��ȫ�ֱ�������ռ�ÿռ�Ƚϴ�

������3���ֲ�����������ͬ����ȫ�ֱ��������ֲ��������ȡ�*/
#include<stdio.h>
int x=1,y=2;
int z=x+y;
void f1()//�������ظ�ʱ����������ʹ�ú����ڲ�����ı�������ʱ�޸��ڲ���������Ӱ���ⲿ���������� 
{
	int x=0;
	printf("f1 x=%d y=%d z=%d\n",x,y,z);
	x+=1;
	printf("x=%d y=%d z=%d\n",x,y,z);
	z=0;
}
void f2()
{
	printf("f2 x=%d y=%d z=%d\n",x,y,z);
	x+=1;
	printf("x=%d y=%d z=%d\n",x,y,z);
	z=0;
}
int main()
{
	f1();
	f2();
	printf("main x=%d y=%d z=%d\n",x,y,z);
	x+=1;
	printf("x=%d y=%d z=%d\n",x,y,z);
}


#include<stdio.h>
int x,y;
void swap()
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
int main()
{
	x=1;y=2;
	printf("x=%d y=%d\n",x,y);
	swap();
	printf("x=%d y=%d\n",x,y);
}



#include<stdio.h>
int s1,s2,s3;
/*4.��̬�洢��ʽ

 ���������ڼ���ϵͳ����̶��Ĵ洢�ռ�ķ�ʽ��

˵����

 ��1���ڳ���ִ�����������ж�ռ�ô洢��Ԫ�������̬�����ڶ���ʱ����ʼ������ֵ��Ϊ0��\0����*/
void count(int a,int b,int c)
{
	s1=a*b;s2=a*c;s3=b*c;
}
int main()
{
	printf("%d %d %d",s1,s2,s3);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	count(a,b,c);
	printf("%d %d %d",s1,s2,s3);
	return 0;
}
