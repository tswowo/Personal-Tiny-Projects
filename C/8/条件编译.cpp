#include<stdio.h>
int main()
{
	//1
//	#ifdef��������˺� #ifndef���û�ж���� 
	#ifndef DEBUG//Ҳ������Ƕ�� 
		printf("NO DEBUG\n");
		#define DEBUG
		#ifdef DEBUG
			printf("DEBUG has difined\n");
		#endif
	#endif//ÿ��ifdef||ifndef�����Ҫ��endif��ԣ�����������}����������������
	
	//2
	#define isRight 0
	#if isRight==1
		printf("Right is Right\n");
	#elif isRight==0
		printf("Right is Worry\n");
	#else
		printf("Unknown\n");
	#endif//ͬ��Ҫ��endif��β 
	
	//3
	for(int i=0;i<10;i++)
	{
		//����������������Ԥ����ģ��ķ�ʽ����ֵ�ڱ�������о͵õ�ȷ�� 
		#if isRight==i
			printf("%d\n",i);
		#endif
	}
}
