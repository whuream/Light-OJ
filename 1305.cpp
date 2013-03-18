#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		int x[6];
		int j;
		for(j=0;j<6;j++) cin>>x[j];
		int X=x[4]-x[2]+x[0];
		int Y=x[5]-x[3]+x[1];
		int S=abs((x[2]-x[0])*(x[5]-x[3])-(x[3]-x[1])*(x[4]-x[2]));
		printf("Case %d: %d %d %d\n",i,X,Y,S);
	}
	return 0;
}