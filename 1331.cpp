#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

#define PI (2*acos(0.0))

double jiao(double a,double b,double c)
{
	double co=(b*b+c*c-a*a)/(2*b*c);
	return acos(co);
}

double ans(double R1,double R2,double R3)
{
	double a=R1+R2;
	double b=R1+R3;
	double c=R2+R3;
	double pre=(a+b+c)/2;
	double rec=sqrt(pre*(pre-a)*(pre-b)*(pre-c));
	return rec-0.5*R1*R1*jiao(c,a,b)-0.5*R2*R2*jiao(b,a,c)-0.5*R3*R3*jiao(a,b,c);
}

int main()
{
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		double R1,R2,R3;
		cin>>R1>>R2>>R3;
		printf("Case %d: %.10f\n",i,ans(R1,R2,R3));
	}
	return 0;
}