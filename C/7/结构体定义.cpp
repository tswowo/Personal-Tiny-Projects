#include<stdio.h>
//�ṹ��Ķ��� 
struct people
{
	char *name;
	int age;
	int num;
	char *major;
};
int main()
{
	//�ṹ����ͨ��ʼ��:
	struct people one={"Bob",18,114,"A"};
	
	//ָ����Ա��ʼ��:
	struct people two;
	two.name="Alice";
	two.age=17;
	two.num=514;
	two.major="B";
	
	//����һ�� 
	printf("%s\n",one.name);
	printf("%d\n",one.age);
	printf("%d\n",one.num);
	printf("%s\n",one.major);
	printf("%s\n",two.name);
	printf("%d\n",two.age);
	printf("%d\n",two.num);
	printf("%s\n",two.major);
}
