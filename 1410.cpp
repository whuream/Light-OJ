#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

#define C 503827

typedef struct _NODE
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
		int N,ans=1;
		scanf("%d",&N);
		vector< vector<int> > m_table(C);
		vector<P> data(N);
		int j;

		for(j=0;j<N;j++)
		{
			scanf("%d%d",&data[j].x,&data[j].y);
		}

		int k;
		for(j=0;j<N;j++)
			for(k=j+1;k<N;k++)
			{
				int dis=(data[j].x-data[k].x)*(data[j].x-data[k].x)+(data[j].y-data[k].y)*(data[j].y-data[k].y);
				int key=dis%C;
				vector<int>::iterator it=m_table[key].begin();
				for(;it!=m_table[key].end();it++) if(*it==dis) break;
				if(it==m_table[key].end()) ans++,m_table[key].push_back(dis);
			}

		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}