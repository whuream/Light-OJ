#include<iostream>
#include<cstdio>

using namespace std;

typedef unsigned long long ull;

ull getans(int n,int k)
{
	if(n<k) return 0;
	ull ans=1;
	int i;
	for(i=n;i>n-k;i--) ans*=i;
	int x=1;
	if(k>n-k) k=n-k;
	for(i=n;i>n-k;i--)
	{
		ans*=i;
		ans/=x;
		x++;
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	int i;
	for(i=0;i<T;i++)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		printf("Case %d: %llu\n",i+1,getans(n,k));
	}
	return 0;
}