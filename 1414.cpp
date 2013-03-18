#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int num(int year)
{
	return (year-1600-1)/4+1-(year-1600-1)/100+(year-1600-1)/400;
}


int main()
{
	freopen("input.txt","r",stdin);
	char all[12][20]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};

	int T;
	cin>>T;

	int i;
	for(i=1;i<=T;i++)
	{
		string month1,month2;
		int day1,day2,year1,year2;
		cin>>month1;
		scanf("%d%*c%d",&day1,&year1);
		cin>>month2;
		scanf("%d%*c%d",&day2,&year2);


		int j;
		for(j=0;j<12;j++)
		{
			if(month1==all[j])
			{
				if(j>=2) year1++;
				break;
			}
		}
		for(j=0;j<12;j++)
		{
			if(month2==all[j])
			{
				if(j>=2) year2++;
				if(j==1 && day2==29) year2++;
				break;
			}
		}
		int ans=num(year2)-num(year1);
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}