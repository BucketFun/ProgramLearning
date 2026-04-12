#include<iostream>
using namespace std;
const int maxn = 1e5+5;
int a[maxn],cnt,n;
void up()
{
	int p = cnt;
	while(p/2 && a[p/2]>a[p])
	{
		swap(a[p/2],a[p]);
		p/=2;
	}
}
void push(int x)
{
	a[++cnt] = x;
	up();
}
void down()
{
	int p =1;
	while(true)
	{
		int l=p*2,r=p*2+1,t=p;
		if(l<=cnt&&a[p]>a[l]) p =l;
		if(r<=cnt&&a[p]>a[r]) p =r;
		if(p!=t) swap(a[p],a[t]);
		else break;
	}
}
void pop()
{
	a[1] = a[cnt--];
	down();
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	int m;
	for(int i=1;i<=n;i++)
		cin>>m,push(m);
	for(int i=1;i<=n;i++)
		cout<<a[1]<<" ",pop();
}
