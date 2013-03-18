#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	int i;
	for(i=1;i<=T;i++)
	{
		long long int N,C;
		scanf("%lld %lld",&N,&C);

		int ans;
		if(N==0) ans=0;
		else ans=C/(2*N);

		ans*C-ans*ans*N>=(ans+1)*C-(ans+1)*(ans+1)*N?1:ans+=1;
		if(N==0) ans=0;
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}