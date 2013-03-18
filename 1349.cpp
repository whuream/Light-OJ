#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct _NODE
{
	int x,y,p;
}NODE;

bool cmpx(NODE a,NODE b)
{
	return a.x>b.x;
}

bool cmpy(NODE a,NODE b)
{
	return a.y>b.y;
}

int m_find(vector<NODE> data,int q)
{
	int pb=0,pe=q-1,tmpb=data[0].p,tmpe=data[q-1].p;
	while(pb!=pe)
	{
		if(tmpb<=tmpe)
		{
			pb++;
			tmpe-=tmpb;
			tmpb=data[pb].p;
		}
		else if(tmpb>tmpe)
		{
			pe--;
			tmpb-=tmpe;
			tmpe=data[pe].p;
		}
	}
	return pb;
}

int main()
{
	int T;
	scanf("%d",&T);

	int i;
	for(i=1;i<=T;i++)
	{
		int m,n,q;
		scanf("%d%d%d",&m,&n,&q);

		vector<NODE> data(q);
		int j;
		for(j=0;j<q;j++)
		{
			scanf("%d%d%d",&data[j].x,&data[j].y,&data[j].p);
		}

		int ansx,ansy;
		sort(data.begin(),data.end(),cmpx);

		ansx=data[m_find(data,q)].x;

		sort(data.begin(),data.end(),cmpy);
		ansy=data[m_find(data,q)].y;
		
		printf("Case %d: %d %d\n",i,ansx,ansy);
	}
	return 0;
}