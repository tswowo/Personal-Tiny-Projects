#include<stdio.h>
main(){
	int num,a,b;
	printf("������һ��������");
	scanf("%d",&num);
	if(num%2==0){
		a=1;
	}
	else{
		a=0;
	}
	if(num>0){
		b=1;
	}
	else{
		b=0;
	}
	switch(a){
		case 1:
			switch(b){
				case 0:
					printf ("������ΪС����0ż��");
					break;
				default:
					printf("������Ϊ��ż��");
					break;
			}
			break;
		default:
			switch(b){
				case 0:
					printf ("������ΪС����0������");
					break;
				default:
					printf("������Ϊ������");
					break;
			}
	}				
}
