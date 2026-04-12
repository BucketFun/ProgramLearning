#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int n,m,root,fa[maxn][20],dep[maxn];
vector<int> e[maxn];
void dfs(int u,int father)
{
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	for(int i=1;i<=19;i++)
	{
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for(int s:e[u])
		if(s!=father) dfs(s,u);
}
int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=19;i>=0;i--)
		if(dep[fa[u][i]]>=dep[v]) 
			u = fa[u][i];
	if(u==v) return u;
	for(int i=19;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u = fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m>>root;
	for(int i=1;i<n;i++)
	{
		int a,b;cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(root,0);
	for(int i=1;i<=m;i++)
	{
		int a,b;cin>>a>>b;
		cout<<lca(a,b)<<"\n";
	}
}
