#include<stdio.h>
int main(){
	int i,n;
	//以字符数组储存输入的数字 
	printf("请输入想要排序的数字数量：");
	scanf("%d",&i);
	int a[i-1];
	fflush(stdin);
	printf("\n请输入想要排序的数字：");
	for(n=0;n<i;n++){
		scanf("%d",&a[n]);
		fflush(stdin);
	}
	//逆序输出
	int f;
	for(f=i-1;f>=0;f--){
		printf("%d",a[f]);
	}
}
