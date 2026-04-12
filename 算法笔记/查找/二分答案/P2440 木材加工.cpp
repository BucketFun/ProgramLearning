#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n,k,m,a[maxn];
bool check(int x)
{
	int c=0;
	for(int i=1;i<=n;i++) c+=(a[i]/x);
	if(c>=k) return true;
	else return false;
}
int find(int l , int r)
{
	while(l+1<r)
	{
		int mid = (l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	return l;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>k;
	long long sum = 0;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	int ans = find(0,sum/k+1);
	cout<<ans;
}
