#include<stdio.h>
int main(){
	int a[9],c,k,i;
	for(k=0;k<=i;k++){
		a[k]=0;
	}
	printf("输入十个不同的整数：");
	for(i=0;i<10;){
		scanf("%d",&c);
		//检测重复数字 
		for(k=0;k<9;k++){
			if(c==a[k])
				break;//如果有重复数字，提前结束循环。k小于9 
		}
		
		if(k==9){//如果没有重复数字，k应该等于i+1 
			a[i]=c;
			i++;
		}
		else if(k<9)
			printf("该整数重复输入。\n");
			fflush(stdin); 
	}
	for(k=0;k<i;k++){//依次输出 
		printf("%d",a[k]);
	}
}
