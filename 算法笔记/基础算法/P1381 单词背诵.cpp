#include<bits/stdc++.h>
using namespace std;

const int maxm = 1e5+5;
string a[maxm];
unordered_map<string,int> cnt;
int num,anslen=maxm;
int main()
{
	ios::sync_with_stdio(0);
	int n = 0;cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		cnt[s]=0;
	}
	int m=0;cin>>m;
	for(int i=1;i<=m;i++) {
		cin>>a[i];
		if(cnt.count(a[i])&&cnt[a[i]]==0) num++,cnt[a[i]]++;
	}
	for(auto& i : cnt)
	{
		i.second=0;
	}
	int l=0,r=0,len=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt.count(a[i])) {l=i,r=i,len=1,cnt[a[i]]++;break;}
	}
	while(r<=m && l<=r)
	{
		if(len<num){
			r++;
			if(cnt.count(a[r])){
				if(cnt[a[r]]==0) len++;
				cnt[a[r]]++;
			}
		}
		if(len==num)
		{
			if(cnt.count(a[l]))
			{
				cnt[a[l]]--;
				if(cnt[a[l]]==0) len--;
			}
			if(anslen>r-l+1) anslen = r-l+1;
			l++;
		}
	}
	cout<<num<<"\n"<<anslen;
}
