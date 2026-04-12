#include<bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
VI a,b;
VI stoi4(string s)
{//字符串转为4高精度数组
	VI ret;
	int i = s.size()-1;
	while(i-3>=0) ret.push_back(stoi(s.substr(i-3,4))),i-=4;
	if(i>=0) ret.push_back(stoi(s.substr(0,i+1)));
	return ret;
}
void pt4(VI a)
{//打印4高精度数组
	for(int i=a.size()-1;i>=0;i--)
	{
		if(a[i]/1000 || i==(int)a.size()-1) cout<<a[i];
		else if(a[i]/100) cout<<"0"<<a[i];
		else if(a[i]/10) cout<<"00"<<a[i];
		else if(a[i]) cout<<"000"<<a[i];
		else cout<<"0000";
	}
}
VI plus4(VI& a,VI& b)
{//高精度数组4的加法
	VI ret;
	int m = max(a.size(),b.size());
	int up=0;
	for(int i=0;i<m;i++)
	{
		int sum=0;
		if(i<(int)a.size()) sum+=a[i];
		if(i<(int)b.size()) sum+=b[i];
		ret.push_back((sum+up)%10000);
		up = (sum+up)/10000;
	}
	if(up) ret.push_back(up);
	return ret;
}
VI minus4(VI a,VI b)
{//高精度4的减法，默认a大于b
	VI ret;
	for(int i=0;i<(int)a.size();i++)
	{
		if(i<(int)b.size()) a[i]-=b[i];
		if(a[i]<0) a[i+1]--,a[i]+=10000;
		ret.push_back(a[i]);
	}
	while(ret.size()>1&&ret.back()==0) ret.pop_back();//去除前导0
	return ret;
}
VI mult4(VI& a,VI& b)
{//高精度数组乘高精度数组
	VI ret(a.size()+b.size(),0);
	for(int i=0;i<(int)a.size();i++)
	{
		for(int j=0;j<(int)b.size();j++)
		{
			ret[i+j] = a[i]*b[j];
			ret[i+j+1] = ret[i+j]/10000;
			ret[i+j]%=10000;
		}
	}
	while(ret.size()>1&&ret.back()==0) ret.pop_back();
	return ret;
}
VI div4(VI& a,int b)
{
	VI ret;
	long long k=0;
	for(int i=a.size()-1;i>=0;i--)
	{
		k = k*10000+a[i];
		ret.push_back(k/b);
		k%=b;
	}
	reverse(ret.begin(),ret.end());
	while(ret.size()>1&&ret.back()==0) ret.pop_back();
	return ret;
}
int main()
{
	string sa,sb;
	cin>>sa>>sb;
	a=stoi4(sa),b=stoi4(sb);
	VI ten = {10};
	VI c = mult4(a,ten);
	pt4(c);
}
