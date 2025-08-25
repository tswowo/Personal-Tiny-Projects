#include<iostream>
#include<vector>//使用vector时需要调用头文件<vector>
#include<algorithm>//find()
using namespace std;
int main()
{
	//vector<typename>name;
	//以int为例 
	//1.vector初始化
	vector<int>v1;//创建一个空向量
	vector<int>v21{1,2,3,0,4,5,6,7};//创建八个变量。列表初始化 1
	vector<int>v22={2,4,6,8,10};//创建5个变量。列表初始化 2
	vector<int>v3(6);//开辟六个空间，初始值默认为0 
	vector<int>v4(6,1);//辟六个空间，初始值为1
					//vector<typename>name(n,value);n个重复元素，每个重复元素值为value 
	vector<int>v51(v4);//将v4的值赋给v51
	vector<int>v52=v4;//将v4的值赋给v52
	vector<int>v6(v4.begin(),v4.end());//将v4从从头到尾赋值给v6
	vector<int>v7(v4.rbegin(),v4.rend());//将v4从尾到头赋值给v7
	int a[]={1,2,3};vector<int>v8(a,a+2);//用数组赋值v8
	
	//2.vector容器赋值
	v1.assign(3,8);//name.assign(n,value)清空vector，并以n个value重新填充 
	v21.assign(v22.begin(),v22.end());//清空，并用新分配元素填充
	v22.swap(v3);//交换v22与v3的数据
	
	 
	//3.访问内部元素:
	cout<<"访问内部元素："<<endl;
	//下标访问
	cout<<"下标访问："<<endl;
	vector<int>cs1={1,2,3,4,5,6,7,1,3,5,7,9};
	for(int i=0;i<cs1.size();i++)
		cout<<cs1[i]<<' ';
	cout<<endl;
	//迭代器访问 
	cout<<"迭代器访问："<<endl;
	vector<int>::iterator it;
	for(it=cs1.begin();it!=cs1.end();it++)
		cout<<*it<<' ';
	cout<<endl;
	//范围for访问
	cout<<"范围for访问："<<endl;
	for(auto x:cs1)//或用int访问vector<int>内部数据 
		cout<<x<<' ';
	cout<<endl; 
	
	//4.vector增删改查 
	cout<<"增删改查："<<endl;
	vector<int>cs;
	//name.push_back(<typaname>)尾插 
	cout<<"尾插："<<endl;
	cs.push_back(1);
	cs.push_back(3);
	cs.push_back(5);
	for(int x:cs)
		cout<<x<<' ';
	cout<<endl;
	//name.pop_back()尾删 
	cout<<"尾删："<<endl;
	cs.pop_back();
	for(int x:cs)
		cout<<x<<' ';
	cout<<endl;
	//insert(迭代器位置,(data)) || insert(起始迭代器位置，插入n个数，value)在指定位置插入数据 
	cout<<"指定位置插入："<<endl;
	cs={1,2,3,4,5};
	for(int x:cs)
		cout<<x<<' ';
	cout<<endl;
	
	cs.insert(cs.begin()+1,0);
	for(int x:cs)
		cout<<x<<' ';
	cout<<endl;
	
	cs.insert(cs.end(),11,9);
	for(int x:cs)
		cout<<x<<' ';
	cout<<endl;
	//erase(迭代器位置) || erase(起始迭代器位置,末尾迭代器位置)在指定位置删除数据(左闭右开)
	cout<<"指定位置删除："<<endl;
	cs={1,2,3,4,5,6,7,8,9};
	for(auto x:cs)
		cout<<x<<' ';
	cout<<endl;
	
	cs.erase(cs.end()-1);
	for(auto x:cs)
		cout<<x<<' ';
	cout<<endl;
	
	cs={1,2,3,4,5,6,7,8,9};
	cs.erase(cs.begin(),cs.end()-3);
	for(auto x:cs)
		cout<<x<<' ';
	cout<<endl;
	//5.find(左闭迭代器,右开迭代器,value)返回value的迭代器,若未找到则返回右开迭代器
	//#include<algorithm>
	cout<<"find："<<endl;
	cs={1,2,3,4,5,6,7,8,9};
	it=find(cs.begin(),cs.end(),1);
	cout<<*it<<endl;
	it=find(cs.begin(),cs.end()-1,10);
	cout<<*it<<endl;
	
	
	//6.二维 vector<vector<typename>>
	cout<<"二维向量："<<endl;
	vector<vector<int>>cs2;
	cs2.resize(5);//先初始化第一维
	for(int i=0;i<5;i++)
		cs2[i].resize(i,i);//再初始化第二维
	for(int i=0;i<5;i++)
	{
		/*
		for(auto x=0;x<i;x++)
			cout<<cs2[i][x]<<' ';*/
		for(auto x:cs2[i])
			cout<<x<<' ';
		cout<<endl;
	}
}
