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
		double v1,v2,v3,a1,a2;
		cin>>v1>>v2>>v3>>a1>>a2;

		double t1=v1/a1;
		double t2=v2/a2;

		double dis=t1>t2?t1*v3:t2*v3;
		double p=v1*v1/2/a1+v2*v2/2/a2;

		printf("Case %d: %.10f %.10f\n",i,p,dis);
	}
	return 0;
}