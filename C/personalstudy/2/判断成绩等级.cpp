#include<stdio.h>
#include<ctype.h>
main(){
	int cj;
	printf("请输入学生成绩：");
	scanf("%d",&cj);
	if(isdigit(cj)){
		printf("请输入正确的学生成绩");
	}
	else if(cj>=0&&cj<=100){
		if(cj>=90){
			printf("该学生成绩等级为A");
		}
		else if(cj>=80){
			printf("该学生成绩等级为B");
		}
		else if(cj>=70){
			printf("该学生成绩等级为C");
		}
		else if(cj>=60){
			printf("该学生成绩等级为D");
		}
		else{
			printf("该学生成绩等级为E");
		}
	}
	else{
		printf("请输入正确的学生成绩");
	}
}
