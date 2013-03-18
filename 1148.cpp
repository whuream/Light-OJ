#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	int i;
	for(i=1;i<=T;i++)
	{
		int N;
		scanf("%d",&N);

		int j;
		map<int,int> data;
		for(j=0;j<N;j++)
		{
			int tmp;
			scanf("%d",&tmp);
			data[tmp]++;
		}

		int ans=0;
		map<int,int>::iterator it=data.begin();
		for(;it!=data.end();it++)
		{
			int F=(*it).first;
			int S=(*it).second;
			ans+=((S-1)/(F+1)+1)*(F+1);
		}
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}