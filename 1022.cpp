#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

#define PI (2*acos(0.0))
#define ZERO 1E-9

int main()
{
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		double r;
		cin>>r;
		double ans=(4-PI)*r*r+ZERO;
		printf("Case %d: %.2lf\n",i,ans);
	}
	return 0;
}