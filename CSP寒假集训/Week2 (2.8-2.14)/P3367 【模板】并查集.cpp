#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int arr[maxn],n,m,z;
int read()
{
	int r=0,k=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') k=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		r=r*10+ch-48;
		ch=getchar();
	}
	return r*k;
}
int find(int x)
{
	if(arr[x]==x) return x;
	else return arr[x]=find(arr[x]);
}
void uniset(int x,int y)
{
	int a=find(x);int b=find(y);
	if(a==b) return;
	else arr[a]=b;
}

int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) arr[i]=i;
	int x,y;
	for(int i=1;i<=m;i++)
	{
		z=read(),x=read(),y=read();
		if(z==1) uniset(x,y);
		else{
			if(find(x)==find(y)) printf("Y\n");
			else printf("N\n");
		}
	}
}
