#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

long long f(vector<int> &data,int n)
{
	int i;
	long long ans=0;
	for(i=0;i<n;i++)
	{
		ans+=((long long)n-1-2*i)*data[i];
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);

	int i;
	for(i=1;i<=T;i++)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		vector<int> data(n);

		int j;
		for(j=0;j<n;j++) scanf("%d",&data[j]);

		long long ans=f(data,n);

		printf("Case %d:\n",i);
		for(j=0;j<q;j++)
		{
			int op;
			scanf("%d",&op);

			if(op==1) printf("%lld\n",ans);
			else
			{
				int x,v;
				scanf("%d%d",&x,&v);

				ans+=((long long)n-1-2*x)*(v-data[x]);

				data[x]=v;
			}
		}
	}
	return 0;
}