#include<iostream>
#include<cstdio>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

inline ll chengli(ll a,ll m);
inline ll get_ans(map<int,int> &a);

inline ll chengli(ll a,ll m)
{
	ll ans=1;
	int i;
	for(i=0;i<m-2;i++)
	{
		ans*=a;
		ans%=m;
	}
	return ans;
}

inline ll get_ans(map<int,int> &a)
{
	ll m=1;
	map<int,int>::iterator it=a.begin();
	for(;it!=a.end();it++)
	{
		m*=it->first;
	}

	ll ans=0;
	for(it=a.begin();it!=a.end();it++)
	{
		ll M=m/it->first;
		ll M1=chengli(M,it->first);
		ans+=it->second*M*M1%m;
	}
	return ans%m;
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

		map<int,int> data;
		int j;
		bool po=true;
		for(j=0;j<n;j++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(data[a]==0) data[a]=b;
			else if(data[a]!=b) po=false;
		}
		if(po==false) printf("Case %d: Impossible\n",i);
		else
		{
			ll ans=get_ans(data); 
			printf("Case %d: %ld\n",i,ans);
		}
	}
	return 0;
}