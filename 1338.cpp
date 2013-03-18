#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

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
		while(a=="") getline(cin,a);
		while(b=="") getline(cin,b);

		int j;
		for(j=0;j<a.length();j++) a[j]=tolower(a[j]);
		for(j=0;j<b.length();j++) b[j]=tolower(b[j]);

		sort(a.begin(),a.end());
		sort(b.begin(),b.end());

		int pa1=a.find(' ');
		int pa2=a.rfind(' ');
		if(pa1!=-1)
			a.erase(pa1,pa2+1);

		int pb1=b.find(' ');
		int pb2=b.rfind(' ');
		if(pb1!=-1)
			b.erase(pb1,pb2+1);
		
		//cout<<a<<endl<<b<<endl;

		if(a==b) printf("Case %d: Yes\n",i);
		else printf("Case %d: No\n",i);
	}
	return 0;
}