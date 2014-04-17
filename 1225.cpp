#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	int i;
	for(i=1;i<=T;i++)
	{
		string data;
		scanf("%s",data.c_str());

		int len=data.length();

		cout<<data<<endl;

		int j;
		for(j=0;j<len/2;j++)
		{
			if(data[j]!=data[len-1-j]) break;
		}
		if(j==len/2) printf("Case %d: Yes\n",i);
		else printf("Case %d: No\n",i);
	}
	return 0;
}