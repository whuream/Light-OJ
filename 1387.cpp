#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		printf("Case %d:\n",i);
		int N;
		cin>>N;

		int j,all=0;
		for(j=0;j<N;j++)
		{
			string op;
			cin>>op;
			if(op=="donate")
			{
				int tmp;
				cin>>tmp;
				all+=tmp;
			}
			else cout<<all<<endl;
		}
	}
	return 0;
}