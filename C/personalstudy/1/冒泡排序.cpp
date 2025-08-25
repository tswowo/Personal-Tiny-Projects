#include<stdio.h>
int main(){
	int m,i,k,hu;
	printf("请输入想要排序的数字的数量：");
	scanf("%d",&m);
	int s[m-1];
	
	printf("请依次输入%d个待排序数字：",m);
	for(i=0;i<m;i++){
		scanf("%d",&s[i]);
		fflush(stdin);
	}
	
	for(i=0;i<m;i++){
		for(k=0;k<m;k++){
			if(s[k]<s[k+1]){
				hu=s[k];
				s[k]=s[k+1];
				s[k+1]=hu;
			}
		}
	}
	
	for(i=0;i<m;i++){
		printf("%d\t",s[i]);
	}
} 
