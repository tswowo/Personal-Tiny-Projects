#include<stdio.h>
int ex(int a[],int len,int *max,int *min)//��*min��*max����ȥ����ʵ��Ϊ�� �������ԭ���� 
{
	int i;
	printf("�ַ�������Ϊ��%d\n",len);
	*max=*min=a[0];
	for(i=0;i<len;i++)
	{
		if(a[i]>*max){
			*max=a[i];
		}
		if(a[i]<*min){
			*min=a[i];	
		}
	}
}
int main()
{
	int i,k,max,min;
	printf("i=");
	scanf("%d",&i);
	int a[i];
	for(k=0;k<i;k++)
	{
		fflush(stdin);
		scanf("%d",&a[k]);
	}
	ex(a,i,&max,&min);
	printf("max��%d\n",max);
	printf("min��%d\n",min);
	return 0;
}


