#include<stdio.h>
#include<ctype.h>
main(){
	int cj;
	printf("������ѧ���ɼ���");
	scanf("%d",&cj);
	if(isdigit(cj)){
		printf("��������ȷ��ѧ���ɼ�");
	}
	else if(cj>=0&&cj<=100){
		if(cj>=90){
			printf("��ѧ���ɼ��ȼ�ΪA");
		}
		else if(cj>=80){
			printf("��ѧ���ɼ��ȼ�ΪB");
		}
		else if(cj>=70){
			printf("��ѧ���ɼ��ȼ�ΪC");
		}
		else if(cj>=60){
			printf("��ѧ���ɼ��ȼ�ΪD");
		}
		else{
			printf("��ѧ���ɼ��ȼ�ΪE");
		}
	}
	else{
		printf("��������ȷ��ѧ���ɼ�");
	}
}
