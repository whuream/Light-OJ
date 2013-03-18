#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;

		printf("Case %d:\n",i);

		int M;
		cin>>M;

		int j;
		for(j=0;j<M;j++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(x>x1 && x<x2 && y>y1 && y<y2) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}