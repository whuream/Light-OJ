#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		int n;
		string name;
		cin>>n>>name;
		printf("Case %d: ",i);
		if(name=="Bob")
		{
			if(n%3==0) printf("Alice\n");
			else printf("Bob\n");

		}
		else
		{
			if(n%3==1) printf("Bob\n");
			else printf("Alice\n");
		}
	}
	return 0;
}