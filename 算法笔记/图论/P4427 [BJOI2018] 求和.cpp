#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5+5;
const int MOD = 998244353;
int n,m,to[2*maxn],ne[2*maxn],h[maxn],idx,fa[maxn][22],dep[maxn];
ll s[maxn][60];
queue<int> q;
bool vis[maxn];
void dfs(int u,int f)
{
	for(int i=1;i<=20;i++)
		fa[u][i] = fa[fa[u][i-1]][i-1];
	for(int i=h[u];i;i=ne[i])
	{
		int v = to[i];
		if(v==f) continue;
		fa[v][0] = u;
		dep[v] = dep[u]+1;
		ll mi = 1;
		for(int j=1;j<=50;j++)
		{
			mi = mi*dep[v]%MOD;
			s[v][j] = (s[u][j]+mi)%MOD;
		}
		dfs(v,u);
	}
}
void bfs()
{
	q.push(1);vis[1]=true;
	while(!q.empty())
	{
		int f = q.front();q.pop();
		for(int i=h[f];i;i=ne[i])
		{
			int v = to[i];
			if(vis[v]) continue;
			dep[v] = dep[f]+1;
			fa[v][0] = f;
			for(int j=1;j<=20;j++)
				fa[v][j] = fa[fa[v][j-1]][j-1];
			ll mi = 1;
			for(int j=1;j<=50;j++)
			{
				mi =dep[v]*mi%MOD;
				s[v][j] = (s[f][j]+mi)%MOD;
			}
			vis[v] = true;
			q.push(v);
		}
		
	}
}
int lcd(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;i--)
	{
		if(dep[u]-(1<<i)>=dep[v])
			u = fa[u][i];
	}
	if(u==v) return u;
	for(int i=20;i>=0;i--)
	{
		if(fa[u][i]==fa[v][i]) continue;
		u = fa[u][i];
		v = fa[v][i];
	}
	return fa[u][0];
}
void add(int a,int b)
{
	to[++idx] = b;ne[idx] = h[a];h[a] = idx;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a,b;cin>>a>>b;
		add(a,b);add(b,a);
	}
	dep[1]=0;
	bfs();
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b,k;cin>>a>>b>>k;
		int l = lcd(a,b);
		ll ans = (s[a][k]+s[b][k]-s[l][k]-s[fa[l][0]][k])%MOD;
		ans = (ans+MOD)%MOD;
		cout<<ans<<"\n";
	}
}
