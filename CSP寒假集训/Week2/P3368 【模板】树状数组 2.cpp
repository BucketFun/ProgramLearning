#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
typedef long long ll;
int n,m,a[maxn],op;
ll tree[maxn];
void Add(int pos,int x)
{
	while(pos<=n)
	{
		tree[pos]+=x;
		pos+=pos&(-pos);
	}
}
ll Sum(int pos)
{
	ll ret=0;
	while(pos>0)
	{
		ret+=tree[pos];
		pos-=pos&(-pos);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		Add(i,a[i]-a[i-1]);
	}
	for(int i=1;i<=m;i++)
	{
		cin>>op;
		int x,y,k;
		if(op==1)
		{
			cin>>x>>y>>k;
			Add(x,k),Add(y+1,-k);
		}
		else
		{
			cin>>x;
			cout<<Sum(x)<<"\n";
		}
	}
}
