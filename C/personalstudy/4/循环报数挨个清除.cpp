#include<stdio.h>
int main()
{
	int n,N,i,count=0,m;
	printf("请输入参与人数与报数个数：");
	scanf("%d%d",&N,&m);
	int a[N];
	for(i=0;i<N;i++){
		a[i]=i+1;
	}
	n=N;
	
	while(N>1){
		if(a[i]!=0){
			count++;
			if(count==m){
				printf("\n%d",a[i]);
				a[i]=0;
				count=0;
				N--;
			}
		}
		i++;
		if(i>=n){
			i=0;
		}
		
		
	}
	
	for(i=0;i<n;i++){
		if(a[i]!=0){
			printf("\n最后剩余的人是第%d人",a[i]);
		}
	}
	return 0;
}
