//if it's me, i will go to the hospital to see my friend but not go on build my house
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		long long int a,b,c;
		cin>>a>>b>>c;
		if(a*a+b*b==c*c
			|| a*a+c*c==b*b
			|| b*b+c*c==a*a)
			printf("Case %d: yes\n",i);
		else printf("Case %d: no\n",i);
	}
	return 0;
}