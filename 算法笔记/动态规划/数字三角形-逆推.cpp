#include<bits/stdc++.h>
using namespace std;
const int n = 4;
int a[9][9]={
	{1},
	{4,6},
	{8,3,9},
	{5,7,2,1}
};
int b[9][9];
int p[9][9];
int main()
{
	//记录路径
	for(int x=0;x<=n-1;x++)
	{
		for(int y=0;y<=x;y++)
		{
			b[x][y]=a[x][y];
		}
	}
	for(int x=n-2;x>=0;x--)
	{
		for(int y=0;y<=x;y++)
		{
			a[x][y]+=max(a[x+1][y],a[x+1][y+1]);
			if(a[x+1][y]<a[x+1][y+1]) p[x][y]=1;
		}
	}
	cout<<a[0][0]<<"\n";
	//输出路径
	for(int x=0,y=0;x<=n-1;x++)
	{
		if(x>0) cout<<"-->";		
		cout<<b[x][y];
		y+=p[x][y];
	}
}
