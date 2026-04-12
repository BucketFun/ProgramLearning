#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
struct dat{
	int delt,l,r;
}sub[maxn];
int n,m,a[maxn],b[maxn];
bool check(int x)
{
	memset(b,0,sizeof(b));
	for(int i=1;i<=x;i++)
	{
		b[sub[i].l]+=sub[i].delt;
		b[sub[i].r+1]-=sub[i].delt;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]+=b[i-1];
	}//还原差分数组
	for(int i=1;i<=n;i++)
	{
		if(b[i]>a[i]) return false;
	}
	return true;
}
int find(int l,int r)
{
	while(l+1<r)
	{
		int mid = (l+r)>>1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	return l;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>sub[i].delt>>sub[i].l>>sub[i].r;
	}
	int ret = find(0,n+1);
	if(ret==n) cout<<0;
	else cout<<-1<<"\n"<<ret+1;
}

