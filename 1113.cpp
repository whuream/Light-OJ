#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);

	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		vector<string> back,next;

		string order,url,out;

		string now="http://www.lightoj.com/";
		
		printf("Case %d:\n",i);

		while(1)
		{
			cin>>order;

			if(order=="QUIT") break;

			else if(order=="VISIT")
			{
				cin>>url;

				back.push_back(now);
				now=url;
				next.resize(0);
				
				out=now;
			}

			else if(order=="BACK")
			{
				if(back.empty()==false)
				{
					next.push_back(now);
					now=back.back();
					back.pop_back();

					out=now;
				}
				else out="Ignored";
			}

			else if(order=="FORWARD")
			{
				if(next.empty()==false)
				{
					back.push_back(now);
					now=next.back();
					next.pop_back();

					out=now;
				}
				else out="Ignored";
			}

			cout<<out<<endl;
		}
	}
	return 0;
}