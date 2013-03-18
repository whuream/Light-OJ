#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<string>
#include<sstream>

using namespace std;

int p100[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

class NODE
{
public:
	map<int,int> p;
	
	void operator+=(NODE &a)
	{
		map<int,int>::iterator it=a.p.begin();
		for(;it!=a.p.end();it++)
		{
			if(this->p[it->first]<it->second)
				this->p[it->first]=it->second;
		}
	}

	void convey(int &n)
	{
		int i;
		for(i=0;i<25;i++)
		{
			if(n%p100[i]==0)
			{
				this->p[p100[i]]++;
				n/=p100[i];
				i--;
			}
		}
		if(n!=1) p[n]++;
	}
};

string add(string &_a,string &_b)
{
	string *a=&_a;
	string *b=&_b;
	if(_a.length()<_b.length()) a=&_b,b=&_a;
	
	int i;
	int pre=0;
	for(i=0;i<a->length();i++)
	{
		if(i<b->length())	(*a)[i]+=(*b)[i]+pre;
		else (*a)[i]+=pre;
		if((*a)[i]>'9')
		{
			pre=1;
			(*a)[i]-='9';
		}
		else pre=0;
	}
	if(pre==1) a->push_back('1');
	return *a;
}

void mul(string &a,const int &n)
{
	string ans,stmp;
	int i;
	for(i=a.length()-1;i>=0;i--)
	{
		int itmp=(a[i]-'0')*n;
		ostringstream ostr;
		ostr<<itmp;
		
		int j;
		for(j=0;j<i;j++) ostr<<'0';

		for(j=ostr.str().length()-1;j>=0;j--) stmp.push_back(ostr.str()[j]);

		ans=add(ans,stmp);
	}
	a=ans;
}

string m_ans(vector<int> &data)
{
	int n=data.end()-data.begin();
	vector<NODE> all(n);
	int i;
	for(i=0;i<n;i++)	all[i].convey(data[i]);
	NODE ans;
	for(i=0;i<n;i++) ans+=all[i];

	string sans;
	sans.push_back('1');
	map<int,int>::iterator it=ans.p.begin();
	for(;it!=ans.p.end();it++)
	{
		for(i=0;i<it->second;i++) mul(sans,it->first);
	}
	return sans;
}

int main()
{
	int T;
	scanf("%d",&T);

	int i;
	for(i=1;i<=T;i++)
	{
		int n;
		scanf("%d",&n);

		vector<int> data(n);
		int j;
		for(j=0;j<n;j++) scanf("%d",&data[j]);

		printf("Case %d: %s\n",i,m_ans(data).c_str());
	}
	return 0;
}