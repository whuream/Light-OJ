#include<iostream>
#include<cstdio>

using namespace std;

int m_p(int a)
{
	int i,ans=1;
	for(i=0;i<a;i++) ans*=2;
	return ans;
}

int ans(int N)
{
	int tmp=N;
	int time=-1;
	int pre=-1;
	int num1=-1;
	while(tmp!=0)
	{
		if(pre==1 && tmp%2==0) break;

		if(tmp%2==0) pre=0;
		else
		{
			pre=1;
			num1++;
		}

		tmp/=2;
		time++;
	}
	int mp=m_p(time);

	int ans=N+mp;

	int key=~(mp*2-1);

	ans=(ans & key)+m_p(num1)-1;
	return ans;
}

int main()
{
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		int N;
		cin>>N;

		printf("Case %d: %d\n",i,ans(N));
	}
	return 0;
}