#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		int n;
		cin>>n;
		vector<int> data(n+1);

		data[0]=2;

		int j;
		for(j=1;j<=n;j++) cin>>data[j];

		int ans=0;
		for(j=1;j<=n;j++)
		{
			if(data[j]!=data[j-1])
				ans+=(data[j]-data[j-1]-1)/5+1;
		}
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}