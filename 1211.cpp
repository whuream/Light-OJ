#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

void swap(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}

int get_min(vector<int> &data)
{
	int min=2000;
	vector<int>::iterator it=data.begin();
	for(;it!=data.end();++it)
	{
		if(*it<min) min=*it;
	}
	return min;
}

int get_max(vector<int> &data)
{
	int max=0;
	vector<int>::iterator it=data.begin();
	for(;it!=data.end();++it)
	{
		if(*it>max) max=*it;
	}
	return max;
}

int main()
{
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		int n;
		scanf("%d",&n);

		vector< vector<int> > data(6,vector<int>(n));

		int j;
		for(j=0;j<n;j++)
		{
			vector<int> tmp(6);

			int k;
			for(k=0;k<6;k++) scanf("%d",&tmp[k]);

			if(tmp[0]>tmp[3]) swap(tmp[0],tmp[3]);
			if(tmp[1]>tmp[4]) swap(tmp[1],tmp[4]);
			if(tmp[2]>tmp[5]) swap(tmp[2],tmp[5]);

			for(k=0;k<6;k++) data[k][j]=tmp[k];
		}

		int X1=get_max(data[0]);
		int X2=get_min(data[3]);
		int Y1=get_max(data[1]);
		int Y2=get_min(data[4]);
		int Z1=get_max(data[2]);
		int Z2=get_min(data[5]);

		if(X1<X2 && Y1<Y2 && Z1<Z2)
		{
			int ans=(X2-X1)*(Y2-Y1)*(Z2-Z1);
			printf("Case %d: %d\n",i,ans);
		}
		else printf("Case %d: 0\n",i);

	}
	return 0;
}