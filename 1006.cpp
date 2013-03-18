#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

#define PRIME 10000007


int a, b, c, d, e, f;

int fn( int n )
{
	int i;
	vector<int> data(n+20);
	data[0]=a%PRIME;
	data[1]=b%PRIME;
	data[2]=c%PRIME;
	data[3]=d%PRIME;
	data[4]=e%PRIME;
	data[5]=f%PRIME;
	
	for(i=6;i<=n;i++)
	{
		data[i]=(data[i-1]+data[i-2]+data[i-3]+data[i-4]+data[i-5]+data[i-6])%PRIME;
	}
	return data[n];
}

int main()
{
    int n, caseno = 0, cases;
	//freopen("input.txt","r",stdin);
	//看来要考虑溢出。
	//I hate this PROBLEM!!

    scanf("%d", &cases);

    while( cases-- )
	{
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}