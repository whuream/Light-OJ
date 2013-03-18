#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

#define PI (2*acos(0.0))

int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		int x[6];
		int j;
		for(j=0;j<6;j++) scanf("%d",&x[j]);

		int r2=(x[2]-x[0])*(x[2]-x[0])+(x[3]-x[1])*(x[3]-x[1]);
		int d2=(x[2]-x[4])*(x[2]-x[4])+(x[3]-x[5])*(x[3]-x[5]);

		double ans=sqrt(double(r2))*acos((2.0*r2-d2)/(2*r2));
		printf("Case %d: %.10f\n",i,ans);
	}
	return 0;
}