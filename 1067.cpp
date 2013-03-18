#include<iostream>
#include<cstdio>

using namespace std;

typedef unsigned long long ull;

#define P 1000003

ull take(int a,int b)
{
    if(a>b-a) a=b-a;
    ull ans=1;
    int x=1;
    int i;
    for(i=b;i>b-a;i--)
    {
        ans*=i;
        ans/=x;
        x++;
        ans%=P;
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);

    int i;
    for(i=1;i<=T;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);

        printf("Case %d: %llu\n",i,take(b,a));
    }
    return 0;
}
