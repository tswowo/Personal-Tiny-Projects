#include<stdio.h>
int main(){
	int i,n;//���ַ����鴢����������� 
	printf("��������Ҫ���������������");
	scanf("%d",&i);
	int a[i-1];
	fflush(stdin);
	printf("\n��������Ҫ��������֣�");
	for(n=0;n<(i-1);n++){
		scanf("%d",&a[n]);
		fflush(stdin);
	}
	//��ʼ����
	int b[i-1];//ѡ�������ԭ���Ǽ���ʣ�������������������õ������е�ĳһ��
	int max1,k,f;
	for(f=0;f<i;f++){
		max1=0;//���ü�¼�����ֵ 
		for(n=0;n<i;n++){ //�������ֵ
			if(max1<=a[n]){ 
				max1=a[n];
				k=n;
			}
		}
	b[f]=max1;//�����ֵ�������� 
	a[k]=0;//�������ֵ�Ӵ���������ȥ��
	}
	
	//������� 
	for(f=0;f<i;f++){
		printf("%d\t",b[f]);
	}
}
