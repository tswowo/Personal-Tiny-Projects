#include<stdio.h>
#include<string.h>
int main(){
	char a[100],b[100];
	gets(a);
	gets(b);
	a[3]='\0';
	int i=0;
	while(a[i]!='\0'){
		i++;
	}
	a[i+1]='\0';
	i=0;
	puts(a);
	while(b[i]!='\0'){
		i++;
	}
	b[i+1]='\0';
	puts(b);
	b[3]='\0';
	strcat(a,b);
	puts(a);
	i=strlen(a);
	
	int ac;
	for(ac=0;ac<=i;ac++){
	printf("\n%c",a[ac]);
	}
}
