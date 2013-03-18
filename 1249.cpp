#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

typedef struct _NODE
{
	string name;
	int vol;
}NODE;

int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		int n;
		cin>>n;

		vector<NODE> data(n);

		int j;
		for(j=0;j<n;j++)
		{
			cin>>data[j].name;
			int x,y,z;
			cin>>x>>y>>z;
			data[j].vol=x*y*z;
		}

		int aver=0;
		for(j=0;j<n;j++) aver+=data[j].vol;
		aver/=n;

		string a,b;
		for(j=0;j<n;j++)
		{
			if(data[j].vol>aver) a=data[j].name;
			if(data[j].vol<aver) b=data[j].name;
		}
		if(a=="") printf("Case %d: no thief\n",i);
		else printf("Case %d: %s took chocolate from %s\n",i,a.c_str(),b.c_str());
	}
	return 0;
}