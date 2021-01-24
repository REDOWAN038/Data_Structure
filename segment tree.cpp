#include<bits/stdc++.h>
using namespace std;
#define sz 1000
int a[sz];
int tree[3*sz];

void init(int node,int begin,int end)
{
	if(begin==end)
	{
		tree[node] = a[begin];
		return;
	}

	int left = 2*node;
	int right = (2*node)+1;
	int mid = (begin+end)/2;

	init(left,begin,mid);
	init(right,mid+1,end);
	tree[node] = tree[left] + tree[right];
}

int sum_query(int node,int begin,int end,int l,int u)
{
	if(l>end || u<begin)
		return 0;
	if(begin>=l && end<=u)
		return tree[node];

	int left = 2*node;
	int right = (2*node)+1;
	int mid = (begin+end)/2;

	return (sum_query(left,begin,mid,l,u) + sum_query(right,mid+1,end,l,u));
}

void update_query(int node,int begin,int end,int idx,int newval)
{
	if(idx<begin || idx>end)
		return;
	if(begin==end)
	{
		tree[node] = newval;
		return;
	}

	int left = 2*node;
	int right = (2*node)+1;
	int mid = (begin+end)/2;

	update_query(left,begin,mid,idx,newval);
	update_query(right,mid+1,end,idx,newval);

	tree[node] = tree[left] + tree[right];
}

int main()
{
	int i,n,q;
	cout<<"enter how many numbers : ";
	cin>>n;

	for(i=1;i<=n;i++)
		cin>>a[i];

	init(1,1,n);

	cout<<"enter how many number for query(sum) : ";
	cin>>q;

	for(i=0;i<q;i++)
	{
		cout<<"enter lower and upper bound : ";
		int l,u;
		cin>>l>>u;
		int ans = sum_query(1,1,n,l,u);
		cout<<ans<<endl;
	}

	cout<<"enter how many number for query(update) : ";
	cin>>q;

	for(i=0;i<q;i++)
	{
		cout<<"enter index number and value : ";
		int idx,newval;
		cin>>idx>>newval;
		update_query(1,1,n,idx,newval);
	}

	cout<<"enter how many number for query(sum) after update : ";
	cin>>q;

	for(i=0;i<q;i++)
	{
		cout<<"enter lower and upper bound : ";
		int l,u;
		cin>>l>>u;
		int ans = sum_query(1,1,n,l,u);
		cout<<ans<<endl;
	}
}
