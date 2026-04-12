#include<bits/stdc++.h>
using namespace std;
int l,n,m;
vector<int> stones(1,0);
bool check(int s)
{
	int now=0,next=1,cnt=0;
	while(now<=n+1&&next<=n+1)//now表示现在所处的位置，n+1为终点石头的下标
	{
		int delt = stones[next] - stones[now];
		if(delt<s) cnt++,next++;
		else now = next++;
	}
	return cnt<=m;
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
	cin>>l>>n>>m;
	int k=0;
	for(int i=1;i<=n;i++) cin>>k,stones.push_back(k);
	stones.push_back(l);
	cout<<find(0,l+1);
}
