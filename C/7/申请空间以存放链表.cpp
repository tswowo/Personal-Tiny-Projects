#include<stdio.h>
#include<stdlib.h>

typedef struct Line{
	//������
	int num;
	int score;
	char name[10];
	//ָ����
	struct Line *next;
}L;

int main()
{
	L *p;
	p=(L *)malloc(sizeof(L));
	scanf("%d",&(p->num));
	printf("%d",p->num)	;
	return 0;
}
