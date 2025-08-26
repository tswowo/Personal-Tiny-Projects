#include<stdio.h>
main(){
	char c;
	scanf("%c",&c);
	if(c>='a'&&c<='z'){
		c+=4;
		if(c>'z')
			c-=26;
	}
	else if(c>='A'&&c<='Z'){
		c+=4;
		if(c>'Z')
			c-=26;
	}
	else if(c>='1'&&c<='9'){
		c+=4;
		if(c>'9')
			c-=9;
	}
	printf("%c",c);
}
