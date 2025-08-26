#include<stdio.h>
int main()
{
    int l,m,u,v,i,k;
    scanf("%d %d",&l,&m);
    int tree[l];
    for(i=0;i<l;i++)
    {
        tree[i]=1;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);
        for(k=u;k<v;k++)
        {
            tree[k]=0; 
        }
    }
    k=0;
    for(i=0;i<=l;i++)
    {
        if(tree[i]==1)
		{
		k++;
    	}
    }
    printf("%d",k);
    return 0;
}
