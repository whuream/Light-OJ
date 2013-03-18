#include<iostream>
#include<cstdio>

using namespace std;

int count(int A,int B)
{
	int cou=(B-A+1)/3*2;
	int yu=(B-A+1)%3;
	long long int lB=(long long int)B;
	if(yu==1 && lB*(lB+1)/2%3==0) cou+=1;
	else if(yu==2) 
	{
		if(lB*(lB+1)/2%3==0) cou+=1;
		if((lB-1)*lB/2%3==0) cou+=1;
	}
	return cou;
}

int main()
{
	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		int A,B;
		scanf("%d%d",&A,&B);
		int ans=count(A,B);
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}