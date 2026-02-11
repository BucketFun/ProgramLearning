/*
<贪心><排序><高精度>
一开始没有思路，没有做这种题的经验。下午的时候看了这道题的题解，掌握大体的思路，发现自己高精度算数没有学过，所以花了一两个小时学习高精度算法。到了晚上自己开始写。
第一次WA：div4()内部对carry取余写成了carry%10000
第二次WA：输出的是m，但m是高位在前，但我是以低位在前输出的
之后都是一个RE：最后输出的时候没有判断m.empty()
这道题花了至少5个小时。不过很有收获
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > people;
bool cmp(const pair<int,int> a,const pair<int,int> b)
{
	if(a.first*a.second==b.first*b.second) return a.second<b.second;
	return a.first*a.second<b.first*b.second;
}
vector<int> mul;//记录乘积
void mult4(int m)
{
	int carry=0;
	for(size_t i=0;i<mul.size();i++)
	{
		carry+=mul[i]*m;
		mul[i]=carry%10000;
		carry/=10000;
	}
	if(carry) mul.push_back(carry);
}
vector<int> save;//储存商，用于寻找最大数
vector<int> m;//储存最大值
bool Max()//true表示要更新
{
	if(m.empty()) return true;
	if(save.size()!=m.size()) return save.size()>m.size();
	for(size_t i=0;i<m.size();i++)
	{
		if(save[i]>m[i]) return true;
		else if(save[i]<m[i]) return false;
	}
	return false;
}
void div4(int m)
{
	save.clear();
	int carry=0;
	int flag=1;
	for(int i=mul.size()-1;i>=0;i--)
	{
		carry=carry*10000+mul[i];
		if(carry/m!=0&&flag) flag=0;
		if(!flag) save.push_back(carry/m);
		carry%=m;
	}
}
int main()
{
	int n;cin>>n;
	pair<int,int> p;
	for(int i=0;i<=n;i++)
	{
		cin>>p.first>>p.second;
		people.push_back(p);
	}
	//排序
	sort(people.begin()+1,people.end(),cmp);
	//计算
	mul.push_back(people[0].first);//皇帝左手
	for(int i=1;i<=n;i++)
	{
		div4(people[i].second);
		if(!save.empty()&&Max()) m=save;
		mult4(people[i].first);
	}
	//输出
	if(m.empty())
	{
		cout<<0;
		return 0;
	}
	cout << m[0];
	for (size_t i = 1; i < m.size(); i++)
	{
		if (m[i] >= 1000) cout << m[i];
		else if (m[i] >= 100) cout << "0" << m[i];
		else if (m[i] >= 10)  cout << "00" << m[i];
		else                  cout << "000" << m[i];
	}
}
