#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n,m,a[maxn],ans,l[maxn],r[maxn],v[maxn];
typedef long long ll;
ll s,b[maxn],sn[maxn];
ll check(int w)
{
	memset(b,0,sizeof(b));
	memset(sn,0,sizeof(sn));
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=w) b[i] = b[i-1]+v[i],sn[i]=sn[i-1]+1;
		else b[i]=b[i-1],sn[i]=sn[i-1];
	}
	ll sum=0;
	for(int i=1;i<=m;i++)
	{
		sum+=((sn[r[i]]-sn[l[i]-1] )*(b[r[i]]-b[l[i]-1]));
	}
	return sum;
}
ll find(int L,int R)
{
	while(L+1<R)
	{
		int mid = (L+R)>>1;
		if(check(mid)<=s) R = mid;
		else L = mid;
	}
	ll re1 = abs(check(L)-s),re2 = abs(check(R)-s);
	return re1 < re2 ? re1:re2;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m>>s;
	int Max = -1;
	for(int i=1;i<=n;i++) {cin>>a[i]>>v[i];if(v[i]>Max) Max = v[i];}
	for(int i=1;i<=m;i++) cin>>l[i]>>r[i];
	cout<<find(0,Max+1)<<"\n";
}
