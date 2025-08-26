#include<stdio.h>
#include<stdlib.h>

typedef struct Line{
	//Êı¾İÓò
	int num;
	int score;
	char name[10];
	//Ö¸ÕëÓò
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
