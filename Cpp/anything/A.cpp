#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    while(n--)
    {
        int m,d,c;
        cin>>m>>d>>c;
        if(m<6||(m==6&&d<=20))
        {
            if(c==1800)
                cout<<"Ok!\n";
            if(c>1800)
                cout<<"^_^\n";
            if(c<1800)
                cout<<"Need more!\n";
        }
        else if(m<7||(m==7&&d<=11))
        {
            if(c==2000)
                cout<<"Ok!\n";
            if(c>2000)
                cout<<"^_^\n";
            if(c<2000)
                cout<<"Need more!\n";
        }
        else
            cout<<"Too late!\n";
    }
    return 0;
}
