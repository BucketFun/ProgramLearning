//思路：找到两个最小的数合并
#include<queue>
#include<iostream>

using namespace std;
priority_queue<int,vector<int>,greater<int> > pq;//默认小的在顶
long long ans=0;
int main()
{
	int n=0;cin>>n;
	int in=0;
	for(int i=0;i<n;i++)
	{
		cin>>in;
		pq.push(in);
	}
	for(int i=1;i<n;i++)
	{
		int sum=0;
		sum+=pq.top();
		pq.pop();
		sum+=pq.top();
		pq.pop();
		pq.push(sum);
		ans+=sum;
	}
	cout<<ans;
}
