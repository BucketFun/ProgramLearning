#include<bits/stdc++.h>
using namespace std;
int a[10] = {2,1,3,5,4,8,7,6,9,70};
int b[10];
void msort(int* arr ,int l ,int r)
{
	if(l==r) return;
	int mid = (l+r)>>1;
	msort(arr,l,mid);
	msort(arr,mid+1,r);
	int i = l,j = mid+1,k=l;
	while(i<=mid && j<=r)
	{
		if(a[i]<=a[j]) b[k++] = a[i++];
		else b[k++]=a[j++];
	}
	while(i<=mid) b[k++] = a[i++];
	while(j<=r) b[k++] = a[j++];
	for(int i=l;i<=r;i++) a[i]=b[i];
}
int main()
{
	msort(a,0,9);
	for(int i=0;i<10;i++)
		cout<<b[i]<<" ";
}
