#include<stdio.h>

int a[32][32]={0};
int min;
int tarx,tary;
int n,m;

void DFS(int x,int y,int ans)
{
	if(x<0||y<0||x>=n||y>=m||a[x][y]==1)return;
	if(x==tarx&&y==tary)
	{
		if(ans<min)
			min=ans;
		return;
	}
	a[x][y]=1;
	DFS(x-2,y+1,ans+1);
	DFS(x-2,y-1,ans+1);
	DFS(x+2,y+1,ans+1);
	DFS(x+2,y-1,ans+1);
	DFS(x+1,y+2,ans+1);
	DFS(x+1,y-2,ans+1);
	DFS(x-1,y+2,ans+1);
	DFS(x-1,y-2,ans+1);
	a[x][y]=0;
}

int main()
{
	scanf("%d%d",&n,&m);
	int x,y;
	scanf("%d%d",&x,&y);
	scanf("%d%d",&tarx,&tary);
	min=9999;
	DFS(x,y,0);
	printf("%d\n",min);
    return 0;
}
