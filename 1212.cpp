#include<deque>
#include<iostream>
#include<cstdio>
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
		printf("Case %d:\n",i);

		int n,m;
		deque<int> data;
		int num=0;
		cin>>n>>m;

		int j;
		for(j=0;j<m;j++)
		{
			string op;
			cin>>op;

			if(op=="pushLeft")
			{	
				int x;
				cin>>x;
				if(num!=n)
				{
					data.push_front(x);
					num++;
					printf("Pushed in left: %d\n",x);
				}
				else printf("The queue is full\n");
			}

			if(op=="pushRight")
			{
				int x;
				cin>>x;
				if(num!=n)
				{
					data.push_back(x);
					num++;
					printf("Pushed in right: %d\n",x);
				}
				else printf("The queue is full\n");
			}

			if(op=="popLeft")
			{
				if(num!=0)
				{
					int x=data.front();
					data.pop_front();
					num--;
					printf("Popped from left: %d\n",x);
				}
				else printf("The queue is empty\n");
			}

			if(op=="popRight")
			{
				if(num!=0)
				{
					int x=data.back();
					data.pop_back();
					num--;
					printf("Popped from right: %d\n",x);
				}
				else printf("The queue is empty\n");
			}
		}
	}
	return 0;
}