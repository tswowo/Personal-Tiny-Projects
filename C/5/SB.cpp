#include<stdio.h>
void star(void){
	for(int count=0;count<10;count++){
		printf("*");
	}
}

int main(void){
	star();
	printf("\nSSS\n");
	star();
	return 1;
}
