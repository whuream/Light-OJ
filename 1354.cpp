#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

bool check(string &data,int num,int p)
{
	int lease=p-7;
	int i;
	while(num!=0)
	{
		if(num%2+'0'!=data[p]) return false;
		num/=2;
		p--;
	}
	for(i=p;i>=lease;i--)
		if(data[i]!='0') return false;
	return true;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	cin>>T;
	getchar();

	int i;
	for(i=1;i<=T;i++)
	{
		int a,b,c,d;
		scanf("%d%*c%d%*c%d%*c%d",&a,&b,&c,&d);
		string data;
		cin>>data;
		if(check(data,a,7) &&check(data,b,16) && check(data,c,25) &&check(data,d,34))
			printf("Case %d: Yes\n",i);
		else printf("Case %d: No\n",i);
	}
	return 0;
}