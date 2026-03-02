#include<bits/stdc++.h>
using namespace std;
int n,m,v,w,s;
int g[20005],f[20005],q[20005];
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		memcpy(g,f,sizeof(f));
		cin>>v>>w>>s;
		for(int j=0;j<v;j++)
		{
			int h=0,t=-1;
			for(int k=j;k<=m;k+=v)
			{
				if(h<=t && q[h]<k-s*v) h++;
				if(h<=t) f[k] = max(g[k] , g[q[h]]+(k-q[h])/v*w);
				while(h<=t&&g[k]>=g[q[t]]+(k-q[t])/v*w) t--;
				q[++t]=k;
			}
		}
	}
	cout<<f[m];
}
