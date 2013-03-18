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
		int m,n,ans;
		scanf("%d%d",&m,&n);

		if(m==1 || n==1) ans=m*n;
		else if(m==2 || n==2)
		{
			int le=m!=2?m:n;
			if(le%4==0) ans=le;
			else if(le%4==1) ans=le+1;
			else if(le%4==2) ans=le+2;
			else  ans=le+1;
		}
		else ans=int((m*n+1)/2);

		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}