#include <stdio.h>
void lost(){/* 空类型void，无返回值*/ 
	printf("Hello\n");	
}

int add(int a,int b){
	int c;
	c=a+b;
	return c;
}

int main(){/*要有主函数*/
	int d,e,f;
	scanf("%d%d",&d,&e);
	f=add(d,e);
	printf("%d",f);
}
