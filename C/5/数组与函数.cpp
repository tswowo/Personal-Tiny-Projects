#include <stdio.h>//数组元素做参数，等价于变量
int ff(int k){
	k=9;
	printf("函数中k的值为%d\n",k);
	return k;
} 
main(){
	int a[]={1,2,3,4,5};
	ff(a[2]);
	printf("主函数中a[2]的值为%d\n",a[2]);
	return 0;
}
#include <stdio.h>//数组名做参数，传递的是数组的地址
int ff(int k[]){
	k[2]=9;
	printf("函数中k[2]的值为%d\n",k[2]);
	return k[2];
} 
main(){
	int a[]={1,2,3,4,5};
	ff(a);
	printf("主函数中a[2]的值为%d\n",a[2]);
	return 0;
}
