#include<stdio.h>
int main(){
	int i,k;
	printf("请输入长度：");
	scanf("%d",&i);
	fflush(stdin);
	int num[i];
	printf("请依次输入数字：");
	for (k=0;k<i;k++){
		printf("\n第%d个数是:",k+1);
		scanf("%d",&num[k]);
		fflush(stdin);
	}
	
	//可以这样： 
	/*int *a;
	a=&num[0];//这里写a=&num效果是一样的,指向数组第一个数，而并不会指向整个数组 
	for(k=0;k<i;k++){
		printf("\n%d",*a);
		a+=1;
	}*/
	
	//或者这样：
	for(int *a=num;a<(num+3);a++){
		printf("\n%d",*a);
	}
}
