#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

#define PI (2*acos(0.0))

int main()
{
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		int n,base,ans;
		scanf("%d%d",&n,&base);

		double dn=double(n);
		double dbase=double(base);
		if(n!=0)	
			ans=int( ( dn*log(dn)-dn+0.5*log(2*dn*PI)+1/(12*dn)-1/(360*dn*dn*dn)) 
			/ log(dbase) )+1;
		else ans=1;
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}