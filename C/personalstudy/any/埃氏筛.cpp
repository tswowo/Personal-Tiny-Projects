#include<iostream>
#include<vector>

std::vector<int>ans;
int a[101]={0};

void find_prime()
{
    a[0]=1;
    a[1]=1;
    for(int i=2;i<=100;i++)
        if(a[i]==0)
        {
            a[i]=1;
            for(int j=2;i*j<=100;j++)
                a[i*j]=1;
            ans.push_back(i);
        }
}

int main()
{
    find_prime();
    std::cout<<"num:"<<ans.size()<<std::endl;
    for(auto&x:ans)
        std::cout<<x<<std::endl;
    return 0;
}
	
