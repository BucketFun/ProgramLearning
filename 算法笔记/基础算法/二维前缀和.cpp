#include<bits/stdc++.h>
using namespace std;
int n,m,mat[5010][5010],x,y,v,ans;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>v;
		mat[x+1][y+1] += v;
	}
	for(int i=1;i<=5001;i++)
	{
		for(int j=1;j<=5001;j++)
		{
			mat[i][j]=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1]+mat[i][j];
		}
	}
	for(int i=m;i<=5001;i++)
	{
		for(int j=m;j<=5001;j++)
		{
			ans = max(ans,mat[i][j]-mat[i-m][j]-mat[i][j-m]+mat[i-m][j-m]);
		}
	}
	cout<<ans;
	
}
