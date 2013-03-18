#include<iostream>
#include<string>
#include<cstdio>
#include<string>
#include<sstream>

using namespace std;

int main()
{

	//freopen("input.txt","r",stdin);
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		string a,b;
		cin>>a>>b;

		printf("Case %d: ",i);

		long long int B;

		stringstream tmpB;
		tmpB<<b;
		tmpB>>B;

		int p=0;
		if(a[0]=='-') p++;

		int lb=b.length();
		int la=a.length();
		if(b[0]=='-') lb--;

		if(lb==10) lb--;

		string yu="0";
		
		while(p<la)
		{
			yu=yu+a.substr(p,lb);
			long long int A;
			stringstream tmpA;
			stringstream tmpB;

			tmpA<<yu;
			tmpA>>A;

			tmpB<<A%B;
			tmpB>>yu;

			p+=lb;
		}
		if(yu=="0") printf("divisible\n");
		else printf("not divisible\n");
	}
	return 0;
}