#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
int n,t[200050],d[200050],ans=1000000000,r[200050];
void read(int& x){
	x=0;
	int y=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') y=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x=x*y;
}
void dfs(int ti,int s,int l){
	if (ti==s&&l){                                //如果回到开始说明连成了环 
		ans=min(ans,l);
		return;
	}
//    que.push(s);
//    int l=0;
//    while (!que.empty()){
//        int x=que.front();
//        que.pop();
//        if (x==s&&l){
//            ans=min(ans,l);
//            return;
//        }
//        
//    }
//    if (t[ti]!=-1) que.push(t[ti]);
	if (!d[t[ti]]) {
		d[t[ti]]=1;                                //标记 
		dfs(t[ti],s,l+1);
	}
}
void rmove(int ti){                                //删除ti 
	d[ti]=-1;                                    //标记 
	r[t[ti]]--;                                    //ti的下一个人的入度减一 
	if (!r[t[ti]]&&d[t[ti]]!=-1) rmove(t[ti]);
}
int main(){
	memset(d,0,sizeof(d));
	memset(r,0,sizeof(r));                        //r[i]为第 i 个人的入度 
	int i;
	read(n);
	for (i=1;i<=n;i++){
		read(t[i]);
		r[t[i]]++;
	}
	for (i=1;i<=n;i++){
		if (!r[i]&&d[i]!=-1) rmove(i);            //如果 i 的入度为 0 且还未被删除，则删除i 
	}
	for (i=1;i<=n;i++){
		if (!d[i]){                                //如果i还未搜过且未被删除，则从i开始搜索 
			//cout<<i<<' ';
			dfs(i,i,0);
		}
	}
	//cout<<endl;
	printf("%d",ans);
	return 0;
}

