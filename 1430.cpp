#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>

using namespace std;

typedef struct _NODE
{
	int  HH,MM,SS,yu;
}NODE;

int cmp(NODE &a,NODE &b)
{
	if(a.HH<b.HH) return -1;
	if(a.HH>b.HH) return 1;

	if(a.MM<b.MM) return -1;
	if(a.MM>b.MM) return 1;

	if(a.SS<b.SS) return -1;
	if(a.SS>b.SS) return 1;

	if(a.yu<b.yu) return -1;
	if(a.yu>b.yu) return 1;

	return 0;
}

int main()
{
	int T;
	scanf("%d",&T);

	int i;
	for(i=1;i<=T;i++)
	{
		vector<NODE> all;
		NODE line,begin,end;
		scanf("%d%*c%d%*c%d%*c%d%*c%d%*c%d%*c%d%*c%d%*c%d%*c"
			,&line.HH,&line.MM,&line.SS,&begin.HH,&begin.MM,&begin.SS
			,&end.HH,&end.MM,&end.SS);
		line.yu=0;
		begin.yu=0;
		end.yu=0;

		if(end.HH==0 && end.MM==0 && end.SS==0)
		{
			end.HH=11;
			end.MM=59;
			end.SS=59;
			end.yu=12;
		}
		
		NODE ans;
		int j;
		int k;
		for(j=begin.HH;j<=end.HH;j++)
		{
			int tiao;
			if(line.HH>=6) tiao=-43200;
			else tiao=0;
			for(k=0;k<2;k++)
			{
				ans.HH=j;
				int zuo=7200*line.HH+120*line.MM+2*line.SS+tiao;
				zuo-=3600*ans.HH;
			
				ans.MM=zuo/780;
				zuo%=780;
				ans.SS=zuo/13;
				zuo%=13;
				ans.yu=zuo;
				if(cmp(ans,begin)>=0 && cmp(ans,end)<=0
					&& ans.MM<60 && ans.MM>=0
					&& ans.SS<60 &&ans.SS>=0)
				{
					all.push_back(ans);
				}
				tiao+=43200;
			}
		}
		printf("Case %d: %d\n",i,all.end()-all.begin());
		vector<NODE>::iterator it=all.begin();
		for(;it!=all.end();it++)
		{
			printf("%02d:%02d:%02d",(*it).HH,(*it).MM,(*it).SS);
			if((*it).yu==0) printf("\n");
			else printf(" %d/13\n",(*it).yu);
		}
	}
	return 0;
}