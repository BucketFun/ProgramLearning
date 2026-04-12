#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n,m,mat[maxn][maxn];
bool vis[maxn][maxn];
int dr[4] = {-1,1, 0,0};
int dc[4] = { 0,0,-1,1};
bool check(int r,int c,int x)
{
	if(r==n) return true;
	vis[r][c]=true;
	for(int i=0;i<4;i++)
	{
		int nr = r+dr[i],nc=c+dc[i];
		if(nr<1||nc<1||nr>n||nc>m||vis[nr][nc]||mat[nr][nc]>x) continue;
		if(check(nr,nc,x)) return true;
	}
	return false;
}
int find(int l,int r)
{
	while(l+1<r)
	{
		memset(vis,false,sizeof(vis));
		int mid = (l+r)>>1;
		if(check(1,1,mid)) r = mid;
		else l=mid;
		//cout<<l<<" "<<r<<"\n";
	}
	return r;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mat[i][j];
	cout<<find(0,1001);
}
