#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10;
const int maxm = 2e3+10;
int a[maxn],cnt[maxm],n,m;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=1,r=1,num=1;
	cnt[a[l]]++;
	int ans =maxn,ansl=1,ansr=1;
	
	while(r<=n&&l<=r)
	{
		if(num<m) {r++;if(cnt[a[r]]==0) num++;cnt[a[r]]++;}
		if(num==m){cnt[a[l]]--;if(r-l+1<ans)ans=r-l+1,ansl=l,ansr=r;if(cnt[a[l]]==0) num--;l++;}
	}
	cout<<ansl<<" "<<ansr;
}
