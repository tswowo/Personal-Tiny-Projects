#include<stdio.h>
//数组名做参数，传递的是数组的地址，所以调用函数会修改实参 
//实际上是形参数组和实参数组为同一数组，共同拥有一段内存空间。 
//实际上形参数组为伪数组，是指针，是地址变量。
int f(int b[]){
	int i,num;
	printf("\n%请输入要修改的数字的位置：\n");
	scanf("%d",&i);
	i--;
	printf("\n%修改为：\n");
	scanf("%d",&num);
	b[i]=num;
}

int main(){
	int i,k;
	int a[4];
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
		fflush(stdin);
	} 
	f(a);
	printf("输出：");
	for(k=0;k<5;k++){
		printf("%d\t",a[k]);
	} 
}
