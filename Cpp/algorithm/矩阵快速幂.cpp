#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    long long n,a,b,u,v;
    while(scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&u,&v)!=EOF)
    {
        double c=sqrt(u*u+4*v);
        double x=(u+c)/2.0;
        double y=(u-c)/2.0;
        double len=n*log10(x)+log10(b-a*y)-log10(c);
        printf("%lld\n",(long long)len+1);
    }
    return 0;
}


