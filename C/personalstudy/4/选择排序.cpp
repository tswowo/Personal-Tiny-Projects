#include<stdio.h>
int main(){
	int i,n;//以字符数组储存输入的数字 
	printf("请输入想要排序的数字数量：");
	scanf("%d",&i);
	int a[i-1];
	fflush(stdin);
	printf("\n请输入想要排序的数字：");
	for(n=0;n<(i-1);n++){
		scanf("%d",&a[n]);
		fflush(stdin);
	}
	//开始排序
	int b[i-1];//选择排序的原理是检索剩余待排序数中最大数放置到序列中的某一端
	int max1,k,f;
	for(f=0;f<i;f++){
		max1=0;//重置记录的最大值 
		for(n=0;n<i;n++){ //检索最大值
			if(max1<=a[n]){ 
				max1=a[n];
				k=n;
			}
		}
	b[f]=max1;//将最大值放入序列 
	a[k]=0;//将该最大值从待排序数中去除
	}
	
	//输出序列 
	for(f=0;f<i;f++){
		printf("%d\t",b[f]);
	}
}
