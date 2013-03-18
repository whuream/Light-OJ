#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);
	
	int n;
	cin >> n;

	int i;
	for(i = 1; i <= n; ++ i)
	{
		int a, b;
		cin >> a >> b;
		cout << "Case " << i << ": " << a + b << endl;
	}
	return 0;
}