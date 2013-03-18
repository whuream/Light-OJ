#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

void S(int D,vector<int> &data)
{
	vector<int>::iterator it=data.begin();
	for(;it!=data.end();++it) *it+=D;
}

void M(int D,vector<int> &data)
{
	vector<int>::iterator it=data.begin();
	for(;it!=data.end();++it) *it*=D;
}

void D(int K,vector<int> &data)
{
	vector<int>::iterator it=data.begin();
	for(;it!=data.end();++it) *it/=K;
}

void P(int Y,int Z,vector<int> &data)
{
	int tmp=data[Y];
	data[Y]=data[Z];
	data[Z]=tmp;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		printf("Case %d:\n",i);

		int n,m;
		cin>>n>>m;

		vector<int> data(n);
		int j;
		for(j=0;j<n;j++)
		{
			scanf("%d",&data[j]);
		}

		string op;
		int re=1;
		for(j=0;j<m;j++)
		{
			cin>>op;
			if("R"==op) re++;

			else if("S"==op)
			{
				int D;
				scanf("%d",&D);
				S(D,data);
			}

			else if("M"==op)
			{
				int D;
				scanf("%d",&D);
				M(D,data);
			}

			else if("D"==op)
			{
				int K;
				scanf("%d",&K);
				D(K,data);
			}

			else if("P"==op)
			{
				int Y,Z;
				scanf("%d%d",&Y,&Z);
				if(re%2==1) P(Y,Z,data);
				else P(n-1-Y,n-1-Z,data);
			}
		}

		if(re%2==1)
		{
			for(j=0;j<n-1;j++)
			{
				printf("%d ",data[j]);
			}
			printf("%d\n",data[n-1]);
		}
		else
		{
			for(j=n-1;j>0;j--)
			{
				printf("%d ",data[j]);
			}
			printf("%d\n",data[0]);
		}
	}
	return 0;
}