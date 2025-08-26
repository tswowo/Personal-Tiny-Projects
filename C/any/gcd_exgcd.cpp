#include <iostream>
using namespace std;

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

int exgcd(int a,int b,int&x,int&y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int gcd=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return gcd;
}

int sol(int a, int b) {
    int x, y;
    int g = exgcd(a, b, x, y);
    x = (x % b + b) % b;
    return x;
}

int main() {
    int a, b;
    cin >> a >> b;
    int result = sol(a, b);
    cout <<"gcd:"<<gcd(a,b) << endl;
    cout <<"exgcd:"<<result << endl;
    return 0;
}    
