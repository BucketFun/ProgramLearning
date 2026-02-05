#include<bits/stdc++.h>
using namespace std;
#define maxn 3000005
int n,p;
int inv[maxn];
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>p;
	inv[1]=1;
	cout<<1<<"\n";
	for(int i=2;i<=n;i++)
	{
		inv[i]=1LL*(p-p/i)*inv[p%i]%p;
		cout<<inv[i]<<"\n";
	}
}
