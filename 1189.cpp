#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int main()
{
	long long int data[20]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600
							,6227020800,87178291200,1307674368000,20922789888000,355687428096000
							,6402373705728000,121645100408832000};

	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		long long int n;
		cin>>n;
		vector<int> ans;

		int j;
		for(j=19;j>=0 && n!=0;j--)
		{
			if(data[j]<=n)
			{
				ans.push_back(j);
				n-=data[j];
			}
		}
		if(n!=0) printf("Case %d: impossible\n",i);
		else
		{
			printf("Case %d: ",i);
			vector<int>::reverse_iterator it=ans.rbegin();
			for(;it!=ans.rend()-1;it++)
			{
				printf("%d!+",*it);
			}
			printf("%d!\n",*it);
		}
	}
	return 0;
}