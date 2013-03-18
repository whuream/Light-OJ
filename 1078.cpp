#include<iostream>
#include<cstdio>

using namespace std;

int getans(int n,int d)
{
	int all=d%n;
	int count=1;
	int pre=d%n;
	while(all!=0)
	{
		count++;
		all=(all+pre*10%n)%n;
		pre=pre*10%n;
	}
	return count;
}

int main()
{
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		int n,d;
		cin>>n>>d;
		printf("Case %d: %d\n",i,getans(n,d));
	}
	return 0;
}