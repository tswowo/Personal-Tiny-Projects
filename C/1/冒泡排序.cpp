#include<stdio.h>
int main(){
	int m,i,k,hu;
	printf("��������Ҫ��������ֵ�������");
	scanf("%d",&m);
	int s[m-1];
	
	printf("����������%d�����������֣�",m);
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
