#include<bits/stdc++.h>
using namespace std;
int n,m,v,w,s;
int vv[1000],ww[1000],dp[1000];
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	int num=1;
	for(int i=1;i<=n;i++)
	{
		cin>>v>>w>>s;
		int k=1;
		while(k<=s)
		{
			vv[num]=k*v;
			ww[num++]=k*w;
			s-=k;
			k<<=1;
		}
		if(s)
		{
			vv[num]=s*v;
			ww[num++]=s*w;
		}
	}
	for(int i=1;i<num;i++)
	{
		for(int j=m;j>0;j--)
		{
			if(j>=vv[i]) dp[j] = max(dp[j],dp[j-vv[i]]+ww[i]);
		}
	}
	cout<<dp[m];
}
