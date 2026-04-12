#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n,m,a[maxn],l,r,ST[maxn][20];
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>ST[i][0];
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			ST[i][j] = max(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r;
		int k = log2(r-l);
		cout<<max(ST[l][k],ST[r-(1<<k)+1][k])<<"\n";
	}
}
