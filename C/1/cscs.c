#include<stdio.h>
int main(){
	double a,b,c;
	int d;
	scanf("%d%d",&a,&b);
	printf("\n");
	printf("1.+ 2.- 3.* 4./ 5.%\n");
	scanf("%d",&d);
	printf("\n");
	switch(d){
		case 1:
			printf("%d",a+b);
			break;
		case 2:
			printf("%d",a-b);
			break;
		case 3:
			printf("%d",a*b);
			break;
		case 4:
			printf("%d",a/b);
			break;
	}
}
}
