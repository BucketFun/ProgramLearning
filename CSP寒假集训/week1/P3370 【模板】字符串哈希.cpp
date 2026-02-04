#include<bits/stdc++.h>
using namespace std;
#define base 499
int get_digit(char c)
{
	if(c>='0'&&c<='9') return c-'0'+1;
	else if(c>='a'&&c<='z') return c-'a'+11;
	else if(c>='A'&&c<='Z') return c-'A'+'z'-'a'+11+1;
	else return -1;
}
vector<long long> hashs;

int main()
{
	int n=0;cin>>n;
	string in;
	for(int i=0;i<n;i++)
	{
		cin>>in;
		long long hash=get_digit(in[0]);
		for(size_t j=1;j<in.size();j++)
		{
			hash=hash*base+get_digit(in[j]);
		}
		hashs.push_back(hash);
	}
	sort(hashs.begin(),hashs.end());
	hashs.erase(unique(hashs.begin(),hashs.end()),hashs.end());
	cout<<hashs.size();
}
