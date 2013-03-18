#include<iostream>
#include<cstdio>
#include<vector>

typedef unsigned long long ull;

ull MAX=(ull)1E19;
ull LINE=(ull)1E15;
ull NEXT=(ull)1E4;

using namespace std;

void out(vector<ull> &a)
{
	vector<ull>::reverse_iterator it=a.rbegin();
	for(;it!=a.rend();it++) printf("%llu",*it);
}

//LINE进制表示法，低位在前，高位在后，b向后移位tb位与a相加。
void add(vector<ull> &a,vector<ull> &b,int tb)
{
	int la=a.end()-a.begin();
	int lb=b.end()-b.begin();

	int i;
	if(la<lb+tb)
	{
		for(i=0;i<lb+tb-la;i++)
			a.push_back(0);
	}
	
	la=a.end()-a.begin();

	ull pre=0;
	for(i=0;i<la;i++)
	{
		if(i<tb); 
		else if(i<lb+tb) a[i]+=b[i-tb]+pre;
		else a[i]+=pre;

		if(a[i]>=LINE)
		{
			pre=a[i]/LINE;
			a[i]=a[i]%LINE;
		}
		else pre=0;
	}
	if(pre!=0) a.push_back(pre);
}

void mul(vector<ull> &a,ull n)
{
	int la=a.end()-a.begin();
	int i;
	vector<ull> ans(la);
	for(i=0;i<la;i++)
	{
		ull tmp=n*a[i];
	}
}


int main()
{
	ull tmpa[6]={111111111111111,222222222222222,333333333333333,444444444444444,55555555555555,0};
	ull tmpb[6]={999999999999999,222222222222222,333333333333333,444444444444444,55555555555555,66666666666666};
	vector<ull> a;
	vector<ull> b;
	
	int i;
	for(i=0;i<6;i++) a.push_back(tmpa[i]),b.push_back(tmpb[i]);
	add(a,b,1);
	out(a);
	
	return 0;
}