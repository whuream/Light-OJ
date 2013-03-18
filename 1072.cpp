#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

#define PI (2*acos(0.0))

int main()
{
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		double R,ans;
		int n;
		cin>>R>>n;

		ans=R/(1+1/sin(PI/n));

		printf("Case %d: %.10lf\n",i,ans);
	}
	return 0;
}