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
		int r1,r2,h,p;
		cin>>r1>>r2>>h>>p;
		double R1=double(p)*(r1-r2)/h+r2;
		double R2=r2;
		double H1=p+double(r2)*h/(r1-r2);
		double H2=double(r2)*h/(r1-r2);

		double ans=1.0/3*PI*R1*R1*H1-1.0/3*PI*R2*R2*H2;
		printf("Case %d: %.10f\n",i,ans);
	}
	return 0;
}