#include<stdio.h>
#include<string.h>
int main(){
	int i=0;
	char a[50];
	gets(a);
	while(a[i]!='\0'){
		printf("%d\n",i);
		i++;
	}
	printf("×Ö·û´®³¤¶ÈÎª£º%d",i);
}
