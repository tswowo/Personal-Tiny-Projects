#include<iostream>
#include<queue>
#include<random>

class qcompare
{
	public:
		bool operator()(int a,int b)
		{
			return a<b;
		}
};

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    
	std::priority_queue<int,std::vector<int>,qcompare>q;
	for(int i=0;i<10;i++)
		q.push(dis(gen));
	while(!q.empty())
	{
		auto x=q.top();
		q.pop();
		std::cout<<x<<std::endl;
	}
	return 0;
}
