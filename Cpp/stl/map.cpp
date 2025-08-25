#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	//即键值对，可修改实值，不可修改key
	
	//1.初始化 
	std::map<string,int>month;//像这样就定义了一个以string为索引，并拥有相关联指向int的指针
	//像这样初始化一个map 
	map<int,char>itoc={{0,'0'},{1,'1'},{2,'2'},{3,'3'},{4,'4'},{5,'5'},{6,'6'},{7,'7'},{8,'8'},{9,'9'}};
//	itoc={{0,'0'},{1,'1'},{2,'2'},{3,'3'},{4,'4'},{5,'5'},{6,'6'},{7,'7'},{8,'8'},{9,'9'}};
//	cout<<itoc[0];
	
	//2.插入
	month.insert(std::make_pair("Jan",1));
	month.insert(std::pair<string,int>("Feb",2));
	month.insert({"Mar",3});
	month.insert(std::map<string,int>::value_type("Apr",4));
	month["May"]=5;
//	month["May"]=0;//可以像这样改变实值 
	
	//3.遍历输出 
	//正向遍历 
	for(auto x=itoc.begin();x!=itoc.end();x++)
		cout<<x->first<<' '<<x->second<<endl;
	for(map<string,int>::iterator x=month.begin();x!=month.end();x++)
		cout<<x->first<<' '<<x->second<<endl;
	//反向遍历 
	for(auto x=itoc.rbegin();x!=itoc.rend();x++)
		cout<<x->first<<' '<<x->second<<endl;
	for(map<string,int>::reverse_iterator x=month.rbegin();x!=month.rend();x++)
		cout<<x->first<<' '<<x->second<<endl;
	//数组的方式
	for(int i=0;i<itoc.size();i++)//注意，这里没有使用month例子 
		cout<<itoc[i]<<endl;//使用itoc例子，是因为itoc的key属于int(0~9) 
		
	//4.查看map大小
	cout<<month.size()<<' '<<itoc.size()<<'\n';
	
	
	
	
	//5.查找并获取元素 
	
	//count()函数判断关键字是否存在
	if(month.count("Feb"))
		cout<<"value found\n";
	else
		cout<<"value no found\n";
	if(itoc.count(1))
		cout<<"value found\n";
	else
		cout<<"value no found\n";
	//find()函数判断关键字是否存在
	map<string,int>::iterator iter1=month.find("Jan");
	if(iter1!=month.end())
		cout<<"value found\n";
	else
		cout<<"value no found\n"; 
	auto iter2=itoc.find(123);
	if(iter2!=itoc.end())
		cout<<"value found\n";
	else
		cout<<"value no found\n";
		
	//6.从map中删除元素
	map<int,string>a={
	{1,"0001"},{2,"0010"},{3,"0011"},{4,"0100"},{5,"0101"},{6,"0110"},{7,"0111"},{8,"1000"},{9,"1001"}};
	a.erase(a.find(1));//迭代器删除 
	a.erase(2);//key删除 
	a.erase(a.begin(),a.begin()+2);//迭代器范围删除
	a.clear();//清空map
}
