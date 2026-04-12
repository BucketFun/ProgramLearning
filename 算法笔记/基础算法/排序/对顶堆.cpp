#include<bits/stdc++.h>
using namespace std;

priority_queue<int> a;//大根堆
priority_queue<int,vector<int>,greater<int> > b;//小根堆

int main()
{
	ios::sync_with_stdio(0);
	int n,w;
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		if(b.empty()||x>=b.top()) b.push(x);
		else a.push(x);
		int k = max(1,i*w/100);
		while((int)b.size()>k) a.push(b.top()),b.pop();
		while((int)b.size()<k) b.push(a.top()),a.pop();
		cout<<b.top()<<" ";
	}
}
