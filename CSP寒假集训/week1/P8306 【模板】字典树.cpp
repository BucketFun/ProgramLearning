#include<bits/stdc++.h>
using namespace std;
#define M 3000005
int tree[M][65], cnt[M], idx;
int get_digit(char c) {
	if (c >= '0' && c <= '9') return c - '0';
	else if (c >= 'a' && c <= 'z') return c - 'a' + '9' - '0' + 1;
	else if (c >= 'A' && c <= 'Z') return c - 'A' + 'z' - 'a' + 1;
	else return -1;
}
void insert(string& s) {
	int p = 0;
	for (size_t i = 0; i < s.size(); i++) {
		int num = get_digit(s[i]);
		if (!tree[p][num]) tree[p][num] = ++idx;
		p = tree[p][num];
		cnt[p]++;	
	}
}
int search(string& s) {
	int p = 0;
	for (size_t i = 0; i < s.size(); i++) {
		int num = get_digit(s[i]);
		if (!tree[p][num]) return 0;
		p = tree[p][num];
	}
	return cnt[p];
}
void clear()
{
	for(int i=0;i<idx;i++)
	{
		for(int j=0;j<65;j++)
		{
			tree[i][j]=0;
		}
		cnt[i]=0;
	}
	idx=0;
}
int main() {
	int T = 0;
	cin >> T;
	while (T--) {
		clear();
		int a, b;
		cin >> a >> b;
		string s;

		while (a--) {
			cin>>s;
			insert(s);
		}
		while (b--) {
			cin>>s;
			cout << search(s)<<"\n";
		}
	}
}
