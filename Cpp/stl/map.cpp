#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	//����ֵ�ԣ����޸�ʵֵ�������޸�key
	
	//1.��ʼ�� 
	std::map<string,int>month;//�������Ͷ�����һ����stringΪ��������ӵ�������ָ��int��ָ��
	//��������ʼ��һ��map 
	map<int,char>itoc={{0,'0'},{1,'1'},{2,'2'},{3,'3'},{4,'4'},{5,'5'},{6,'6'},{7,'7'},{8,'8'},{9,'9'}};
//	itoc={{0,'0'},{1,'1'},{2,'2'},{3,'3'},{4,'4'},{5,'5'},{6,'6'},{7,'7'},{8,'8'},{9,'9'}};
//	cout<<itoc[0];
	
	//2.����
	month.insert(std::make_pair("Jan",1));
	month.insert(std::pair<string,int>("Feb",2));
	month.insert({"Mar",3});
	month.insert(std::map<string,int>::value_type("Apr",4));
	month["May"]=5;
//	month["May"]=0;//�����������ı�ʵֵ 
	
	//3.������� 
	//������� 
	for(auto x=itoc.begin();x!=itoc.end();x++)
		cout<<x->first<<' '<<x->second<<endl;
	for(map<string,int>::iterator x=month.begin();x!=month.end();x++)
		cout<<x->first<<' '<<x->second<<endl;
	//������� 
	for(auto x=itoc.rbegin();x!=itoc.rend();x++)
		cout<<x->first<<' '<<x->second<<endl;
	for(map<string,int>::reverse_iterator x=month.rbegin();x!=month.rend();x++)
		cout<<x->first<<' '<<x->second<<endl;
	//����ķ�ʽ
	for(int i=0;i<itoc.size();i++)//ע�⣬����û��ʹ��month���� 
		cout<<itoc[i]<<endl;//ʹ��itoc���ӣ�����Ϊitoc��key����int(0~9) 
		
	//4.�鿴map��С
	cout<<month.size()<<' '<<itoc.size()<<'\n';
	
	
	
	
	//5.���Ҳ���ȡԪ�� 
	
	//count()�����жϹؼ����Ƿ����
	if(month.count("Feb"))
		cout<<"value found\n";
	else
		cout<<"value no found\n";
	if(itoc.count(1))
		cout<<"value found\n";
	else
		cout<<"value no found\n";
	//find()�����жϹؼ����Ƿ����
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
		
	//6.��map��ɾ��Ԫ��
	map<int,string>a={
	{1,"0001"},{2,"0010"},{3,"0011"},{4,"0100"},{5,"0101"},{6,"0110"},{7,"0111"},{8,"1000"},{9,"1001"}};
	a.erase(a.find(1));//������ɾ�� 
	a.erase(2);//keyɾ�� 
	a.erase(a.begin(),a.begin()+2);//��������Χɾ��
	a.clear();//���map
}
