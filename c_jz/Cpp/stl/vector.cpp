#include<iostream>
#include<vector>//ʹ��vectorʱ��Ҫ����ͷ�ļ�<vector>
#include<algorithm>//find()
using namespace std;
int main()
{
	//vector<typename>name;
	//��intΪ�� 
	//1.vector��ʼ��
	vector<int>v1;//����һ��������
	vector<int>v21{1,2,3,0,4,5,6,7};//�����˸��������б��ʼ�� 1
	vector<int>v22={2,4,6,8,10};//����5���������б��ʼ�� 2
	vector<int>v3(6);//���������ռ䣬��ʼֵĬ��Ϊ0 
	vector<int>v4(6,1);//�������ռ䣬��ʼֵΪ1
					//vector<typename>name(n,value);n���ظ�Ԫ�أ�ÿ���ظ�Ԫ��ֵΪvalue 
	vector<int>v51(v4);//��v4��ֵ����v51
	vector<int>v52=v4;//��v4��ֵ����v52
	vector<int>v6(v4.begin(),v4.end());//��v4�Ӵ�ͷ��β��ֵ��v6
	vector<int>v7(v4.rbegin(),v4.rend());//��v4��β��ͷ��ֵ��v7
	int a[]={1,2,3};vector<int>v8(a,a+2);//�����鸳ֵv8
	
	//2.vector������ֵ
	v1.assign(3,8);//name.assign(n,value)���vector������n��value������� 
	v21.assign(v22.begin(),v22.end());//��գ������·���Ԫ�����
	v22.swap(v3);//����v22��v3������
	
	 
	//3.�����ڲ�Ԫ��:
	cout<<"�����ڲ�Ԫ�أ�"<<endl;
	//�±����
	cout<<"�±���ʣ�"<<endl;
	vector<int>cs1={1,2,3,4,5,6,7,1,3,5,7,9};
	for(int i=0;i<cs1.size();i++)
		cout<<cs1[i]<<' ';
	cout<<endl;
	//���������� 
	cout<<"���������ʣ�"<<endl;
	vector<int>::iterator it;
	for(it=cs1.begin();it!=cs1.end();it++)
		cout<<*it<<' ';
	cout<<endl;
	//��Χfor����
	cout<<"��Χfor���ʣ�"<<endl;
	for(auto x:cs1)//����int����vector<int>�ڲ����� 
		cout<<x<<' ';
	cout<<endl; 
	
	//4.vector��ɾ�Ĳ� 
	cout<<"��ɾ�Ĳ飺"<<endl;
	vector<int>cs;
	//name.push_back(<typaname>)β�� 
	cout<<"β�壺"<<endl;
	cs.push_back(1);
	cs.push_back(3);
	cs.push_back(5);
	for(int x:cs)
		cout<<x<<' ';
	cout<<endl;
	//name.pop_back()βɾ 
	cout<<"βɾ��"<<endl;
	cs.pop_back();
	for(int x:cs)
		cout<<x<<' ';
	cout<<endl;
	//insert(������λ��,(data)) || insert(��ʼ������λ�ã�����n������value)��ָ��λ�ò������� 
	cout<<"ָ��λ�ò��룺"<<endl;
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
	//erase(������λ��) || erase(��ʼ������λ��,ĩβ������λ��)��ָ��λ��ɾ������(����ҿ�)
	cout<<"ָ��λ��ɾ����"<<endl;
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
	//5.find(��յ�����,�ҿ�������,value)����value�ĵ�����,��δ�ҵ��򷵻��ҿ�������
	//#include<algorithm>
	cout<<"find��"<<endl;
	cs={1,2,3,4,5,6,7,8,9};
	it=find(cs.begin(),cs.end(),1);
	cout<<*it<<endl;
	it=find(cs.begin(),cs.end()-1,10);
	cout<<*it<<endl;
	
	
	//6.��ά vector<vector<typename>>
	cout<<"��ά������"<<endl;
	vector<vector<int>>cs2;
	cs2.resize(5);//�ȳ�ʼ����һά
	for(int i=0;i<5;i++)
		cs2[i].resize(i,i);//�ٳ�ʼ���ڶ�ά
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
