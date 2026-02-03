#include<bits/stdc++.h>
using namespace std;
struct point
{
	int pos;
	int val;
}a[500005];
int ranks[500005],trees[500005],n;
bool cmp(point a,point b)
{
	if(a.val==b.val) return a.pos<b.pos;
	return a.val<b.val;
}
inline void add(int m)
{
	while(m<=n)
	{
		trees[m]++;
		m+=m&(-m);
	}
}
long long sum(int pos)
{
	long long ret=0;
	while(pos>0)
	{
		ret+=trees[pos];
		pos-=pos&(-pos);
	}
	return ret;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].val;
		a[i].pos=i;
	}
	//离散化
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		ranks[a[i].pos]=i;
	}
	//构建树状数组
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		add(ranks[i]);
		ans+=(i-sum(ranks[i]));
	}
	cout<<ans;
}
