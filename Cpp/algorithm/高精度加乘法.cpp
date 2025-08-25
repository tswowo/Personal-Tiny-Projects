#include<bits/stdc++.h>
using namespace std;

string multiply(const string string1,const string string2)
{
	vector<int>a(string1.size(),0);
	vector<int>b(string2.size(),0);
	for(int i=0;i<a.size();i++)
		a[i]=string1[i]-'0';
	for(int i=0;i<b.size();i++)
		b[i]=string2[i]-'0';
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	vector<int>ans(a.size()+b.size(),0);
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b.size();j++)
			ans[i+j]+=a[i]*b[j];
	int tmp=0;
	for(int i=0;i<ans.size();i++)
	{
		tmp+=ans[i];
		ans[i]=tmp%10;
		tmp/=10;
	}
	if(tmp>0)
		ans.push_back(tmp/10);
	while(ans.size()>1&&ans.back()==0)
		ans.pop_back();
	string ansstring(ans.size(),0);
	for(int i=0;i<ans.size();i++)
		ansstring[i]=ans[i]+'0';
	reverse(ansstring.begin(),ansstring.end());
	return ansstring;
}

string add(const string string1,const string string2)
{
	string a=string1,b=string2;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string ans(max(a.size(),b.size()),'0');
	for(int i=0;i<a.size()||i<b.size();i++)
	{
		if(i<a.size())
			ans[i]=ans[i]-'0'+a[i];
		if(i<b.size())
			ans[i]=ans[i]-'0'+b[i];
	}
	int tmp=0;
	for(int i=0;i<ans.size();i++)
	{
		tmp+=(ans[i]-'0');
		ans[i]=(tmp%10)+'0';
		tmp/=10;
	}
	if(tmp>0)
		ans+=(tmp+'0');
	reverse(ans.begin(),ans.end());
	return ans;
}

int main()
{
	int n;
	cin>>n;
	string ans="0",doadd="1",docnt="2";
	while(n--)
	{
		ans=add(ans,doadd);
		doadd=multiply(doadd,docnt);
		docnt=add(docnt,"1");
	}
	cout<<ans;
	return 0;
}
