#include <stdio.h>
void f(int a){
	printf("主调函数传递过来的值为%d\n",a);
	a=36;
	printf("被调函数改变后的值为%d\n",a);
}
main(){
	int k;
	k=99;
	printf("调用函数前变量的值为%d\n",k);
	f(k);
	printf("调用函数后变量的值为%d\n",k);
}
