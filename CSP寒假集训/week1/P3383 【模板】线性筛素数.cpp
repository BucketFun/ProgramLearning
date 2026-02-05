#include<bits/stdc++.h>
using namespace std;
#define M 1e8+10
int primes[(int)M],pos;
bool is_prime[(int)M];

int main()
{
	ios::sync_with_stdio(0);
	int n=0;cin>>n;
	for(int i=2;i<n;i++)
	{
		if(is_prime[i]==false) primes[++pos]=i;
		for(int j=1;j<=pos&&i*primes[j]<(int)M;j++)
		{
			is_prime[i*primes[j]]=true;
			if(i%primes[j]==0) break;
		}
	}
	int m=0;cin>>m;
	while(m--)
	{
		cin>>n;
		cout<<primes[n]<<"\n";
	}
}
