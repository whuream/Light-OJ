#include<iostream>
#include<cstdio>
#include<map>
#include<vector>

using namespace std;

#define LINE 1000000000
#define NEXT 10000

typedef unsigned long long ull;

int p[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

inline void get_prime(map<int,int> &a,int n);
inline void m_main();
inline void get_m(map<int,int> &a,vector<int> &b);
inline void add_map(map<int,int> &a,map<int,int> &b);
inline void out(vector<ull> &a);
inline int pow(int a,int b);
inline void one_map(map<int,int> &a);
inline void get_ans(vector<ull> &a,map<int,int> &b);
inline void mul(vector<ull> &a,ull n);

inline void get_ans(vector<ull> &a,map<int,int> &b)
{
	a.push_back(1);
	map<int,int>::iterator it=b.begin();
	ull tmp=1;
	for(;it!=b.end();it++)
	{
		if(tmp*it->second>=NEXT)
		{
			mul(a,tmp);
			tmp=it->second;
		}
		else tmp*=it->second;
	}
	mul(a,tmp);
}

inline void mul(vector<ull> &a,ull n)
{
	ull pre=0;
	vector<ull>::iterator it=a.begin();
	for(;it!=a.end();it++)
	{
		*it=*it*n+pre;
		if(*it>=LINE)
		{
			pre=*it/LINE;
			*it%=LINE;
		}
		else pre=0;
	}
	if(pre!=0) a.push_back(pre);
}

inline void one_map(map<int,int> &a)
{
	map<int,int>::iterator it=a.begin();
	for(;it!=a.end();it++) it->second=pow(it->first,it->second);
}

inline int pow(int a,int b)
{
	int i,ans=1;
	for(i=0;i<b;i++) ans*=a;
	return ans;
}

inline void out(vector<ull> &a)
{
	vector<ull>::reverse_iterator it=a.rbegin();
	printf("%llu",*it);
	it++;
	for(;it!=a.rend();it++) printf("%09llu",*it);
}

inline void get_prime(map<int,int> &a,int n)
{
	int i;
	for(i=0;i<25;i++)
	{
		if(n%p[i]==0)
		{
			a[p[i]]++;
			n/=p[i];
			i--;
		}
	}
	if(n!=1) a[n]++;
}

inline void add_map(map<int,int> &a,map<int,int> &b)
{
	map<int,int>::iterator it=b.begin();
	for(;it!=b.end();it++) if(a[it->first]<it->second) a[it->first]=it->second;
}

inline void get_m(map<int,int> &a,vector<int> &b)
{
	vector<int>::iterator it=b.begin();
	for(;it!=b.end();it++)
	{
		map<int,int> tmp;
		get_prime(tmp,*it);
		add_map(a,tmp);
	}
}

inline void m_main()
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

		map<int,int> tmp_map;
		get_m(tmp_map,data);
		one_map(tmp_map);

		vector<ull> ans;
		get_ans(ans,tmp_map);

		printf("Case %d: ",i);
		out(ans);
		printf("\n");
	}
}


int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	m_main();
	return 0;
}