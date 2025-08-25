#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

int main()
{
	while(1)
	{
		system("cls");
		bool flag=false;
		for(int i=0;i<100;i++)
		{
			system("data.exe > data.txt");
			system("baoli.exe < data.txt > baoli.out");
			system("second.exe < data.txt > second.out");
			if(system("fc baoli.out second.out > nul"))
			{
				flag=true;
				break;
			}
		}
		if(flag)
			system("fc baoli.out second.out");
		system("pause");
	}
	return 0;
}
