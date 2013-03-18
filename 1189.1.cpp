#include<iostream>

using namespace std;

int main()
{
	int i,j;
	long long int pre=1;
	freopen("output.txt","w",stdout);
	for(i=1;i<=20;i++)
	{
		cout<<pre*i<<endl;
		pre*=i;
	}
	return 0;
}