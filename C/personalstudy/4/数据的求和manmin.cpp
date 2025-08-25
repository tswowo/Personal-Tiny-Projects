#include<stdio.h>
int main(){
	int n,i;
	printf("请输入学生人数：");
	scanf("%d",&n);
	int a[n-1];
	//初始化数组 
	for(i=0;i<=n-1;i++){
		a[i]=0;
	}
	//获取学生分数 
	printf("\n请输入学生分数：\n");
	for(i=0;i<=n-1;i++){
		scanf("%d",&a[i]);
	}
	//求平均值 
	float s=0;
	for(i=0;i<=n-1;i++){
		s+=a[i];
	}
	s/=i;
	//查询最小值 
	int min1=a[0];
	for(i=0;i<n;i++){
		if(min1>=a[i])
			min1=a[i];
	}
	//查询最大值
	int max1=a[0];
	for(i=0;i<n;i++){
		if(max1<=a[i])
			max1=a[i];
	}
	printf("\n学生分数的最大值为%d，最小值为%d，平均值为%.2f。",max1,min1,s);
}
