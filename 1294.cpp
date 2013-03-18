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
		long long int n,m;
		cin>>n>>m;
		printf("Case %d: %lld\n",i,n*m/2);
	}
	return 0;
}