#include<iostream>
#include<cstdio>

using namespace std;

bool get_ans(int n)
{
	int count=0;
	while(n!=0)
	{
		if(n%2==1) count++;
		n/=2;
	}
	return count%2;
}

int main()
{
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		int n;
		cin>>n;
		if(get_ans(n)) printf("Case %d: odd\n",i);
		else printf("Case %d: even\n",i);
	}
	return 0;
}