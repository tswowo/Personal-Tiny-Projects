#include<stdio.h>
int main(){
	int n,i;
	printf("������ѧ��������");
	scanf("%d",&n);
	int a[n-1];
	//��ʼ������ 
	for(i=0;i<=n-1;i++){
		a[i]=0;
	}
	//��ȡѧ������ 
	printf("\n������ѧ��������\n");
	for(i=0;i<=n-1;i++){
		scanf("%d",&a[i]);
	}
	//��ƽ��ֵ 
	float s=0;
	for(i=0;i<=n-1;i++){
		s+=a[i];
	}
	s/=i;
	//��ѯ��Сֵ 
	int min1=a[0];
	for(i=0;i<n;i++){
		if(min1>=a[i])
			min1=a[i];
	}
	//��ѯ���ֵ
	int max1=a[0];
	for(i=0;i<n;i++){
		if(max1<=a[i])
			max1=a[i];
	}
	printf("\nѧ�����������ֵΪ%d����СֵΪ%d��ƽ��ֵΪ%.2f��",max1,min1,s);
}
