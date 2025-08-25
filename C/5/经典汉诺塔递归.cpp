#include<stdio.h>
int a[8]={0},b[8]={0},c[8]={0};
int *p1=a,*p2=b,*p3=c;
void plate(char x,char y,char z,int n)
{
	if(n==1)
	{
		if(x=='A'&&y=='B')
		{
			printf("%d %c->%c\n",*p1,x,y);
			*(++p2)=*p1;
			*(p1--)=0;
		}
		else if(x=='A'&&y=='C')
		{
			printf("%d %c->%c\n",*p1,x,y);
			*(++p3)=*p1;
			*(p1--)=0;
		}
		else if(x=='B'&&y=='A')
		{
			printf("%d %c->%c\n",*p2,x,y);
			*(++p1)=*p2;
			*(p2--)=0;
		}
		else if(x=='B'&&y=='C')
		{
			printf("%d %c->%c\n",*p2,x,y);
			*(++p3)=*p2;
			*(p1--)=0;
		}
		else if(x=='C'&&y=='A')
		{
			printf("%d %c->%c\n",*p3,x,y);
			*(++p1)=*p3;
			*(p1--)=0;
		}
		else if(x=='C'&&y=='B')
		{
			printf("%d %c->%c\n",*p3,x,y);
			*(++p2)=*p1;
			*(p2--)=0;
		}
	}
	else
	{
		plate(x,z,y,n-1);
		plate(x,y,z,1);
		plate(z,y,x,n-1);
	}
}


int main()
{
	int x;
	while(scanf("%d",&x)!=EOF)
	{
		p2=b;
		p3=c;
		for(int i=0;i<x;i++)
		{
			a[i]=x-i;
			p1=a+i;
		}
		plate('A','C','B',x);
		printf("\n");
	}
	return 0;	
}
