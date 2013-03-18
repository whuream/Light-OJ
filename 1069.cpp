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
		int a,b,ans;
		cin>>a>>b;
		ans=19+4*a+4*abs(a-b);
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}