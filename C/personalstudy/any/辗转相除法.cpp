#include<stdio.h>


int gcd(long int a,long int b)
{
	return (b==0?a:gcd(b,a%b));
}

int bei(long int a,long int b)
{
    return (a*b)/gcd(a,b);
}
	
