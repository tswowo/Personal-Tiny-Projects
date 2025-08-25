int ss(int a)
{
	int i;
	i=2;
	scanf("%d",&a);
	while(i<=a){
		if(a%i==0)
			break;
		i++;
	}
	if(a==1)return 1;
	else if(a==i)return 1;
	else if(a>i)return 0;
}
