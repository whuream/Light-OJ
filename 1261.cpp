#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

bool in(vector<int> &ans,int n)
{
	vector<int>::iterator it=ans.begin();
	for(;it!=ans.end();++it)
	{
		if(*it==n) return true;
	}
	return false;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		int n,m,K;
		cin>>n>>m>>K;
		vector< vector<int> > data(n,vector<int>(K));

		int j,k;
		for(j=0;j<n;j++)
			for(k=0;k<K;k++)
				cin>>data[j][k];

		int p;
		cin>>p;
		vector<int> ans(p);
		for(j=0;j<p;j++) cin>>ans[j];

		for(j=0;j<n;j++)
		{
			for(k=0;k<K;k++)
			{
				if(data[j][k]<0 && in(ans,-data[j][k])==false) break; 
				if(data[j][k]>0 && in(ans,data[j][k])==true) break;
			}
			if(k==K) break;
		}
		if(j==n) printf("Case %d: Yes\n",i);
		else printf("Case %d: No\n",i);
	}
	return 0;
}