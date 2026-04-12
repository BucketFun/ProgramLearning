#include<bits/stdc++.h>
using namespace std;
int a[100005];

void qsort(int* arr,int l,int r)
{
	if(l==r) return;
	int i = l-1,j=r+1,x=a[(l+r)/2];
	while(i<j)
	{
		do i++;while(arr[i]<x);
		do j--;while(arr[j]>x);
		if(i<j) swap(arr[i],arr[j]);
	}
	qsort(arr,l,j);
	qsort(arr,j+1,r);
}
int main()
{
	ios::sync_with_stdio(0);
	int n=0;cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	qsort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
