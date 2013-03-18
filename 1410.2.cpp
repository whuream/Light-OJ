#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct _P
{
	int x,y;
}P;

int main()
{
	int T;
	scanf("%d",&T);

	int i;
	for(i=1;i<=T;i++)
	{
		int N;
		scanf("%d",&N);
		vector<int> all(N*(N-1)/2);
		vector<P> data(N);
		
		int j;
		for(j=0;j<N;j++) scanf("%d%d",&data[j].x,&data[j].y);

		int k;
		for(j=0;j<N-1;j++)
			for(k=j+1;k<N;k++)
				all[j*(2*N-1-j)/2+k-j-1]=(data[j].x-data[k].x)*(data[j].x-data[k].x)
				+(data[j].y-data[k].y)*(data[j].y-data[k].y);
		sort(all.begin(),all.end());
		vector<int>::iterator it=unique(all.begin(),all.end());
		int ans=it-all.begin();
		printf("Case %d: %d\n",i,ans+1);
	}
	return 0;
}