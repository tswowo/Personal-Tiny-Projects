#include"stdio.h"
#include"math.h"
main(){
	float a,b,c,p,C,s;
	printf("����������ʵ����");
	scanf("%f%f%f",&a,&b,&c);
	if(a+b>c&a-b<c){
		p=(a+b+c)/2;
		C=a+b+c;
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		printf("\n�����ε��ܳ�Ϊ��%f�����Ϊ��%f",C,s);
	}
	else{
		printf("�����%f,%f,%f���ܹ���������",a,b,c);
	}
}
