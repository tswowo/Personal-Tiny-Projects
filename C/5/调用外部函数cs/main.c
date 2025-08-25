#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) //其实不放在同一个文件夹内也能编译运行，只要知道位置 
{
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d",add(x,y));
	return 0;
}
