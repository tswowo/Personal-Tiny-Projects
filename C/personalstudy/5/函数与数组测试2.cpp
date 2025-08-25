#include<stdio.h>
//数组元素做参数，等价于变量，这段代码并不会修改数组的内容 

int f(int b){
	int num;
	printf("\n%修改为：\n");
	scanf("%d",&num);
	b=num;
}

int main(){
	int i,k;
	int a[4];
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
		fflush(stdin);
	} 
	printf("\n%请输入要修改的数字的位置：\n");
	scanf("%d",&i);
	i--;
	f(a[i]);
	printf("输出：");
	for(k=0;k<5;k++){
		printf("%d\t",a[k]);
	} 
}
