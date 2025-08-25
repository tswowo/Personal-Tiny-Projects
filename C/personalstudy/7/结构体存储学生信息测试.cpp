    #include<stdio.h>
    int main()
    {
        int n;
        scanf("%d",&n);
        char *name[n],*ch[1];
        float sc1[n],sc2[n],temp;
        for(int i=0;i<n;i++)
            scanf("%s%f%f",&name[i],&sc1[i],&sc2[i]);
        for(int i=0;i<n;i++)for(int k=0;k<n-1;k++)
        {
            if(sc1[k]<sc1[k+1])
            {
                temp=sc1[k];sc1[k]=sc1[k+1];sc1[k+1]=temp;
                temp=sc2[k];sc2[k]=sc2[k+1];sc2[k+1]=temp;
                ch[0]=name[k];
				name[k]=name[k+1];
				name[k+1]=ch[0];
            }
            else if(sc1[k]==sc1[k+1]&&sc2[k]<sc2[k+1])
            {
                temp=sc1[k];sc1[k]=sc1[k+1];sc1[k+1]=temp;
                temp=sc2[k];sc2[k]=sc2[k+1];sc2[k+1]=temp;
                ch[0]=name[k];name[k]=name[k+1];name[k+1]=ch[0];
			}
        }
        int i=0;
        while(i<n)
        {
        	if(sc1[i]==sc1[i+1]&&sc2[i]==sc2[i+1])
            {
                printf("%d %s %.2f %.2f",i+1,name[i],sc1[i],sc2[i]);
                printf("%d %s %.2f %.2f",i+1,name[i+1],sc1[i],sc2[i]);
                i++;
            }
            else
            {
                printf("%d %s %.2f %.2f",i+1,name[i],sc1[i],sc2[i]);
            }
            i++;
        }
}
