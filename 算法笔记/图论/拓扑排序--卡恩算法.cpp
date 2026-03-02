#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
vector<int> e[maxn],tp;
int din[maxn],n;
queue<int> p;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		while(true)
		{
			int in =0;
			cin>>in;
			if(in==0) break;
			else e[i].push_back(in),din[in]++;
		}
	}
	for(int i=1;i<=n;i++)
		if(din[i]==0) 
			p.push(i);
	while(!p.empty())
	{
		int t = p.front();p.pop();
		for(auto s:e[t])
			if(--din[s]==0) 
				p.push(s);
		tp.push_back(t);
	}
	for(size_t i=0;i<tp.size();i++)
		cout<<tp[i]<<" ";
}
