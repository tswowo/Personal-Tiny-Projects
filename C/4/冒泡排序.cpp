#include<stdio.h>
int main(){
	int i,n,f,c;//以字符数组储存输入的数字 
	printf("请输入想要排序的数字数量：");
	scanf("%d",&i);
	int a[i];
	fflush(stdin);
	printf("\n请输入想要排序的数字：");
	for(n=0;n<i;n++){
		scanf("%d",&a[n]);
		fflush(stdin);
	}
	//开始排序 
	for(n=0;n<(i-1);n++){
		for(f=0;f<(i-1);f++){
			if(a[f]>a[f+1]){
				c=a[f];
				a[f]=a[f+1];
				a[f+1]=c;
			}
		}
	}
	
	
	for(n=0;n<i;n++){
		printf("%d\t",a[n]);
	}
	return 0;
}
