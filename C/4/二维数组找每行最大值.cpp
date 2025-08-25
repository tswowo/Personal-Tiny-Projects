#include"stdio.h"
int main(){
	int x,m,n,a[4][4]={{1,4,5,7},{0,2,1,5},{1},{23,45,12,78}};
	for(m=0;m<=3;m++){
		for(n=0;n<=3;n++){
			x=a[m][n];
			if(x>=a[m][1]&&x>=a[m][2]&&x>=a[m][3]&&x>=a[m][0])
				break;
		}
		printf("第%d行的最大值为%d\n",m+1,x);
	}
}
