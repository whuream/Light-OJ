#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int T;
	scanf("%d",&T);

	int i;
	for(i=1;i<=T;i++)
	{
		int n,P,Q;
		cin>>n>>P>>Q;

		vector<int> weight(n);
		int j;
		for(j=0;j<n;j++) cin>>weight[j];
		sort(weight.begin(),weight.end());

		int ans=0,allwei=0;
		for(j=0;j<n;j++)
		{
			allwei+=weight[j];
			if(allwei>Q || ans==P) break;
			ans++;
		}
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}