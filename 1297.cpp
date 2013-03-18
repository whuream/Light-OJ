#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	int i;
	for(i=1;i<=T;i++)
	{
		double L,W;
		scanf("%lf%lf",&L,&W);

		double ans=(L+W-sqrt(L*L+W*W-L*W))/6;
		ans=4*ans*ans*ans-2*(L+W)*ans*ans+L*W*ans;
		printf("Case %d: %.10lf\n",i,ans);
	}
	return 0;
}