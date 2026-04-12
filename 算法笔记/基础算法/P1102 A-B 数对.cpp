#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
long long n,c,ans,a[maxn];
unordered_map<long long,long long> cnt;
//双指针：
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin>>n>>c;
//	for(int i=1;i<=n;i++) cin>>a[i];
//	sort(a+1,a+n+1);
//	int l=1,r=1;
//	for(int k=1;k<=n;k++)
//	{
//		while(l<=n && a[l]-a[k]< c) l++;
//		while(r<=n && a[r]-a[k]<=c) r++;
//		ans+=r-l;
//	}
//	cout<<ans;
//}

//哈希表：
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=cnt[a[i]-c];
	}
	cout<<ans;
}
