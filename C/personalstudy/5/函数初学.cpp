#include <stdio.h>
void lost(){/* ������void���޷���ֵ*/ 
	printf("Hello\n");	
}

int add(int a,int b){
	int c;
	c=a+b;
	return c;
}

int main(){/*Ҫ��������*/
	int d,e,f;
	scanf("%d%d",&d,&e);
	f=add(d,e);
	printf("%d",f);
}
