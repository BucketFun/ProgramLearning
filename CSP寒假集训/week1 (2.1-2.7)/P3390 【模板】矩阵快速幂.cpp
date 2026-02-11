#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[105][105],a[105][105],n,k;
const int p=1e9+7;
void mult1()
{
	ll c[105][105]={0};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
				c[i][j]=(c[i][j]+a[i][k]*ans[k][j])%p;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans[i][j]=c[i][j];
}
void mult2()
{
	ll c[105][105]={0};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
				c[i][j]=(c[i][j]+a[i][k]*a[k][j])%p;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=c[i][j];
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		ans[i][i]=1;
	while(k)
	{
		if(k&1) mult1();
		mult2();
		k>>=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<ans[i][j]<<" ";
		cout<<"\n";
	}
		
}
