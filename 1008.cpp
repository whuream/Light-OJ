#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		long long int S,x,y;
		cin>>S;

		long long int sq=(long long int)(sqrt(double(S)));

		if(sq%2==0)
		{
			if(sq*sq==S)
			{
				x=sq;
				y=1;
			}
			else
			{
				long long int yu=S-sq*sq;
				if(yu<=sq+1)
				{
					x=sq+1;
					y=yu;
				}
				else
				{
					y=sq+1;
					x=(sq+1)-(yu-(sq+1));
				}
			}
		}
		else
		{
			if(sq*sq==S)
			{
				x=1;
				y=sq;
			}
			else
			{
				long long int yu=S-sq*sq;
				if(yu<=sq+1)
				{
					y=sq+1;
					x=yu;
				}
				else
				{
					x=sq+1;
					y=(sq+1)-(yu-(sq+1));
				}
			}
		}
		cout<<"Case "<<i<<": "<<x<<' '<<y<<endl;
	}

	return 0;
}