#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

int prime[11]={2,3,5,7,11,13,17,19,23,29,31};

int divi(int n)
{
	int ans=1;

	int i;
	for(i=0;i<11;i++)
	{
		int tmp=1;
		while(n%prime[i]==0)
		{
			tmp++;
			n/=prime[i];
		}
		ans*=tmp;
	}
	if(n!=1) ans*=2;
	return ans;
}

bool cmp(int m,int n)
{
	return divi(m)<divi(n);
}

int main()
{
	//freopen("output.txt","w",stdout);
	vector<int> data(1000);

	int i;
	for(i=0;i<1000;i++) data[i]=1000-i;

	stable_sort(data.begin(),data.end(),cmp);

	//for(i=0;i<1000;i++) cout<<data[i]<<' ';

	int T;
	cin>>T;

	for(i=1;i<=T;i++)
	{
		int n;
		cin>>n;
		printf("Case %d: %d\n",i,data[n-1]);
	}

	return 0;
}