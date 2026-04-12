#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6+5;
int a[maxn];
//int main()
//{
//	ios::sync_with_stdio(0);
//	int m=0;cin>>m;
//	long long sum=3;
//	for(int i=1,j=2;i<=m/2;)
//	{
//		if(sum<m){
//			j++;sum+=j;
//		}
//		else if(sum==m && i!=j){
//			cout<<i<<" "<<j<<"\n";
//			j++;sum+=j;
//		}
//		else if(sum>m){
//			sum-=i;i++;
//		}
//	}
//}

int main()
{
	ios::sync_with_stdio(0);
	int m=0;cin>>m;
	int n=0;
	while(a[n]<=m)
	{
		n++;
		a[n]=a[n-1]+n;
	}
	if(a)
}
