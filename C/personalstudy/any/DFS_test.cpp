#include<stdio.h>

int a[1001][1001];
int n,m,ans;

void DFS(int x,int y)
{
	if(x<0||x>=n||y<0||y>=m||a[x][y]==0)
		return;
	a[x][y]=0;
	DFS(x-1,y);
	DFS(x+1,y);
	DFS(x,y+1);
	DFS(x,y-1);
}

int main()
{
	scanf("%d %d",&n,&m);
	ans=0;
	int i,k;
	for(i=0;i<4;i++)
		for(k=0;k<10;k++)
			scanf("%d",&a[i][k]);
	for(i=0;i<n;i++)
		for(k=0;k<m;k++)
		{
			if(a[i][k]!=0)
			{
				ans++;
				DFS(i,k);
			}
		}
	printf("%d",ans);
	return 0;
}
