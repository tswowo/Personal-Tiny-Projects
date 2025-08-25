#include<iostream>
#include<vector>
#include<utility>


int main(){
	std::vector<int>tmp={1,2,3,4,5,6,7,8,9,10};
	
	//std::vector<int>::iterator 
	for(auto x=tmp.begin();x<tmp.end();x++);//毕竟begin()返回的是迭代器 
	//等于这样:for(std::vector<int>::iterator x=tmp.begin();x<tmp.end();x++);
	
	//int 直接访问内部元素 
	for(auto x:tmp);
	//等于这样:for(int x:tmp)
	
	std::vector<std::pair<int,int>>t1={{1,2},{3,4},{5,6},{7,8}};
	
	//std::vector<std::pair<int,int>>::iterator 
	for(auto x=t1.begin();x<t1.end();x++);
//		std::cout<<(*x).first<<' '<<(*x).second<<std::endl;
	//等于这样:for(std::vector<std::pair<int,int>>::iterator x=t1.begin();x<t1.end();x++)
	
	// std::pair<int,int>::iterator
	for(auto x:t1);
//		std::cout<<x.first<<' '<<x.second<<std::endl;
	
}
