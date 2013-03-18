#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	int i;
	for(i=1;i<=T;i++)
	{
		int n,k;
		scanf("%d%d",&n,&k);

		int j,ans=0;
		for(j=2;j<=n;j++)
		{
			ans=(ans+k)%j;
		}

		printf("Case %d: %d\n",i,ans+1);
	}
	return 0;
}