#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

typedef struct _point
{
	int x,y,dx,dy;
}point;

bool cmp(point a,point b)
{
	if(a.x<b.x) return true;
	if(a.x>b.x) return false;
	if(a.y<b.y) return true;
	return false;
}

int main()
{
	int T;
	scanf("%d",&T);

	int i;
	for(i=1;i<=T;i++)
	{
		int L,W,n,K;
		scanf("%d%d%d%d",&L,&W,&n,&K);

		vector<point> data(n);
		int j;
		for(j=0;j<n;j++)
		{
			char tmp[3];
			scanf("%d%d%s",&data[j].x,&data[j].y,tmp);
			if(tmp[0]=='N') data[j].dy=1;
			else data[j].dy=-1;
			if(tmp[1]=='W') data[j].dx=-1;
			else data[j].dx=1;
		}

		for(j=0;j<n;j++)
		{
			data[j].x=((data[j].x+data[j].dx*K)%(2*L)+2*L)%(2*L);
			if(data[j].x>L) data[j].x=2*L-data[j].x;

			data[j].y=((data[j].y+data[j].dy*K)%(2*W)+2*W)%(2*W);
			if(data[j].y>W) data[j].y=2*W-data[j].y;
		}
		sort(data.begin(),data.end(),cmp);

		printf("Case %d:\n",i);
		for(j=0;j<n;j++)
		{
			printf("%d %d\n",data[j].x,data[j].y);
		}
	}
	return 0;
}