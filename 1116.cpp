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
		unsigned long long int W,N,M;
		cin>>W;

		unsigned long long int tmp=W;
		if(tmp%2==1) printf("Case %d: Impossible\n",i);
		else
		{
			while(tmp%2==0) tmp/=2;
			N=tmp;
			M=W/N;
			printf("Case %d: %llu %llu\n",i,N,M);
		}
	}
	return 0;
}