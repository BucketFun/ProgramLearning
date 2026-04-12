#include<bits/stdc++.h>
using namespace std;
int row,col,bar,sr,sc,er,ec,br,bc,ans;
bool mat[10][10];
int dr [4]={-1,0, 0,1};
int dc [4]={ 0,1,-1,0};
bool dfs(int r,int c)
{
	if(r==er&&c==ec){
		ans++;
		return true;
	}
	for(int i=0;i<4;i++)
	{
		int nr=r+dr[i],nc=c+dc[i];
		if(nr<1||nc<1||nr>row||nc>col) continue;
		if(mat[nr][nc]) continue;
		mat[nr][nc] = true;
		dfs(nr,nc);
		mat[nr][nc] = false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>row>>col>>bar>>sr>>sc>>er>>ec;
	for(int i=1;i<=bar;i++)
	{
		cin>>br>>bc;
		mat[br][bc]=true;
	}
	mat[sr][sc] = true;
	dfs(sr,sc);
	cout<<ans;
}
