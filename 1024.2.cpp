#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<vector>
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

void re(string &a)
{
	char tmp;
	int i;
	for(i=0;i<a.length()/2;i++)
	{
		tmp=a[i];
		a[i]=a[a.length()-1-i];
		a[a.length()-1-i]=tmp;
	}
}


//反转的字符数组加法 _a=_a+_b
void add(string &_a,string &_b)
{
	string *a=&_a,*b=&_b;
	if(_a.length()<_b.length()) a=&_b,b=&_a;
	int i;
	int pre=0;
	for(i=0;i<a->length();i++)
	{
		if(i<b->length()) (*a)[i]+=(*b)[i]-'0'+pre;
		else (*a)[i]+=pre;
		
		if((*a)[i]>'9')
		{
			pre=1;
			(*a)[i]-=10;
		}
		else pre=0;
	}
	if(pre==1) a->push_back('1');
	_a=(*a);
}

//反转字符串乘法 a=a*n
void mul(string &a,int n)
{
	int i;
	string ans;
	for(i=0;i<a.length();i++)
	{
		int itmp=(a[i]-'0')*n;

		ostringstream ostr;
		ostr<<itmp;

		int j;
		for(j=0;j<i;j++) ostr<<'0';

		string stmp=ostr.str();
		re(stmp);
		add(ans,stmp);
	}
	a=ans;
}

string getans(vector<int> &data)
{
	int n=data.end()-data.begin();
	NODE all;

	int i;
	for(i=0;i<n;i++) 
	{
		NODE tmp;
		tmp.convey(data[i]);
		all+=tmp;
	}

	string ans;
	ans.push_back('1');
	map<int,int>::iterator it=all.p.begin();
	for(;it!=all.p.end();it++)
	{
		for(i=0;i<it->second;i++) mul(ans,it->first);
	}
	re(ans);
	return ans;
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

		printf("Case %d: %s\n",i,getans(data).c_str());
	}
	return 0;
}