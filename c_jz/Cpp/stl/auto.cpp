#include<iostream>
#include<vector>
#include<utility>


int main(){
	std::vector<int>tmp={1,2,3,4,5,6,7,8,9,10};
	
	//std::vector<int>::iterator 
	for(auto x=tmp.begin();x<tmp.end();x++);//�Ͼ�begin()���ص��ǵ����� 
	//��������:for(std::vector<int>::iterator x=tmp.begin();x<tmp.end();x++);
	
	//int ֱ�ӷ����ڲ�Ԫ�� 
	for(auto x:tmp);
	//��������:for(int x:tmp)
	
	std::vector<std::pair<int,int>>t1={{1,2},{3,4},{5,6},{7,8}};
	
	//std::vector<std::pair<int,int>>::iterator 
	for(auto x=t1.begin();x<t1.end();x++);
//		std::cout<<(*x).first<<' '<<(*x).second<<std::endl;
	//��������:for(std::vector<std::pair<int,int>>::iterator x=t1.begin();x<t1.end();x++)
	
	// std::pair<int,int>::iterator
	for(auto x:t1);
//		std::cout<<x.first<<' '<<x.second<<std::endl;
	
}
