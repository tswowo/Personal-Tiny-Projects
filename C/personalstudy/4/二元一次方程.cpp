#include"stdio.h"
#include"math.h"
int main(){
	float a,b,c,i;
	printf("������A,B,C��ֵ��");
	scanf("%f%f%f",&a,&b,&c);
	
	if(a==0)
		printf("\n%f",-c/b);
	else if(a!=0&&b*b-4*a*c<0)
		printf("\n������ʵ����");
	else if(a!=0&&b*b-4*a*c==0)
		printf("\n%f",-b/2/a);
	else if(a!=0&&b*b-4*a*c>0){
		i=sqrt(b*b-4*a*c);
		printf("\n%f\t%f",(-b+i)/2/a,(-b-i)/2/a);
	}
}
