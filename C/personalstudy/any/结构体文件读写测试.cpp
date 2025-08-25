#include<stdio.h>
#include<string.h>

typedef struct places{
	char name[20];
	int age;
}places;

int main()
{
	int n;
	scanf("%d",&n);
	places pp[n];
	//输入部分 
	for(int i=0;i<n;i++)
		scanf("%s%d",pp[i].name,&pp[i].age);
	//写入部分 
	FILE *p;
	p=fopen("结构体文件读写测试.txt","w");
	fwrite(pp,2,sizeof(places),p);//将存放-结构体数组的容量-单个结构体的大小-输入流
	fclose(p);
	//读取部分 
	places qq[n];
	FILE *q;
	q=fopen("结构体文件读写测试.txt","r");
	fread(qq,2,sizeof(places),q);//将存放-结构体数组的容量-单个结构体的大小-输入流 
	//输出部分 
	for(int i=0;i<n;i++)
	{
		printf("%s %d\n",qq[i].name,qq[i].age);
	}
	return 0;
}
