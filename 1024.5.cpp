#include<iostream>
#include<cstdio>
#include<vector>
#include<map>

using namespace std;

typedef unsigned long long ull;

ull VMAX=(ull)1000000000;
ull IMAX=(ull)10000;

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

void out(vector<ull> &a)
{
	vector<ull>::reverse_iterator it=a.rbegin();
	for(;it!=a.rend();it++) printf("%llu",*it);
}

void mul(vector<ull> &a,ull b)
{
	vector<ull>::iterator it=a.begin();
	for(;it!=a.end();it++) (*it)*=b;

	ull pre=0;
	for(it=a.begin();it!=a.end();it++)
	{
		*it+=pre;
		if((*it)>=VMAX)
		{
			pre=*it/VMAX;
			*it%=VMAX;
		}
		else pre=0;
	}
	if(pre!=0) a.push_back(pre);
}

void getans(vector<int> &data)
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

	vector<ull> ans;
	ans.push_back(1);

	ull utmp=1;
	map<int,int>::iterator it=all.p.begin();
	for(;it!=all.p.end();it++)
	{
		for(i=0;i<it->second;i++)
		{
			mul(ans,it->first);
			/*
			if(utmp*it->first>IMAX)
			{
				mul(ans,utmp);
				utmp=it->first;
			}
			else utmp*=it->first;
			*/
		}
	}
	//mul(ans,utmp);
	out(ans);
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

		printf("Case %d: ",i);
		getans(data);
		printf("\n");
	}
	return 0;
}
