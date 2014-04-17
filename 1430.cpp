#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

class NODE
{
public:
	int HH,MM,SS,yu;

	NODE():HH(0),MM(0),SS(0),yu(0){}
	
	NODE(int h,int m,int s,int y=0)
	{
		HH=h,MM=m,SS=s,yu=y;
	}
	
	bool operator==(const NODE &a)
	{
		if(this->HH==a.HH && this->MM==a.MM && this->SS==a.SS && this->yu==a.yu)
			return true;
		return false;
	}
	
	bool operator>=(const NODE &a)
	{
		if(this->HH>a.HH) return true;
		if(this->HH<a.HH) return false;

		if(this->MM>a.MM) return true;
		if(this->MM<a.MM) return false;

		if(this->SS>a.SS) return true;
		if(this->SS<a.SS) return false;

		if(this->yu>a.yu) return true;
		if(this->yu<a.yu) return false;

		return true;
	}

	bool good()
	{
		if(this->HH>=0 && this->HH<12 && this->MM>=0 && this->MM<60 
			&& this->SS>=0 && this->SS<60 && this->yu>=0 && this->yu<13)
			return true;
		return false;
	}

	void out()
	{
		printf("%02d:%02d:%02d",this->HH,this->MM,this->SS);
		if(this->yu==0) printf("\n");
		else printf(" %d/13\n",this->yu);
	}
};

void m_find(NODE &ans,NODE &line,int tiao)
{
	int tmp=7200*line.HH+120*line.MM+2*line.SS+tiao;
	tmp-=3600*ans.HH;
	ans.MM=tmp/780;
	tmp%=780;
	ans.SS=tmp/13;
	tmp%=13;
	ans.yu=tmp;
}

bool check(NODE &ans,NODE &begin,NODE &end)
{
	if(ans.good()==1 && ans>=begin && end>=ans) return true;
	return false;
}

int main()
{
	int T;
	scanf("%d",&T);

	int i;
	for(i=1;i<=T;i++)
	{
		NODE line,begin,end;
		NODE ans;
		scanf("%d%*c%d%*c%d%*c%d%*c%d%*c%d%*c%d%*c%d%*c%d%*c"
			,&line.HH,&line.MM,&line.SS,&begin.HH,&begin.MM,&begin.SS
			,&end.HH,&end.MM,&end.SS);

		if(line.HH>=6) line.HH-=6;
		if(end==ans) end.HH=11,end.MM=59,end.SS=59,end.yu=12;

		vector<NODE> all;
		for(ans.HH=begin.HH;ans.HH<=end.HH;ans.HH++)
		{
			m_find(ans,line,0);
			if(check(ans,begin,end)) all.push_back(ans);
			m_find(ans,line,43200);
			if(check(ans,begin,end)) all.push_back(ans);
		}

		int count=all.end()-all.begin();
		printf("Case %d: %d\n",i,count);

		vector<NODE>::iterator it=all.begin();
		for(;it!=all.end();it++) it->out();
	}
	return 0;
}