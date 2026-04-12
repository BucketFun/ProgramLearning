#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 1e5+5;
int a[maxn];

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	long long ans =0;
	for(int i=0;i<n;i++) ans+=abs(a[i]-a[n/2]);
	cout<<ans;
}
