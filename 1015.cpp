#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		int N,j,ans=0;
		scanf("%d",&N);
		for(j=0;j<N;j++)
		{
			int tmp;
			scanf("%d",&tmp);
			if(tmp>0) ans+=tmp;
		}
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}