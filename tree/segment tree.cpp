
/// Time Complexity for init function -----> O(nlogn)
/// Time Complexity for sum_query function -----> O(logn)
/// Time Complexity for update_query function -----> O(logn)


#include<iostream>
using namespace std;
#define sz 1000
typedef long long ll;

ll a[sz];

struct info{

    ll prop = 0;               /// taking care of updated value of it's child nodes
    ll val = 0;
}tree[sz*3];

void init(ll node,ll begin,ll end)
{
	if(begin==end)
	{
		tree[node].val = a[begin];
		return;
	}

	ll left = 2*node;
	ll right = (2*node)+1;
	ll mid = (begin+end)/2;

	init(left,begin,mid);
	init(right,mid+1,end);
	tree[node].val = tree[left].val + tree[right].val;
}

ll sum_query(ll node,ll begin,ll end,ll lb,ll ub,ll carry)             /// carry is taking total propagation value for it's child node's
{
	if(lb>end || ub<begin)
		return 0;
	if(begin>=lb && end<=ub)
		return (tree[node].val + (end-begin+1)*carry);      /// child node's number = end-begin+1

	ll left = 2*node;
	ll right = (2*node)+1;
	ll mid = (begin+end)/2;

	return (sum_query(left,begin,mid,lb,ub,carry+tree[node].prop) + sum_query(right,mid+1,end,lb,ub,carry+tree[node].prop));
}

void update_query(ll node,ll begin,ll end,ll lb,ll ub,ll newval)
{
	if(lb>end || ub<begin)
		return;
	if(begin>=lb && end<=ub)
	{
		tree[node].val+=((end-begin+1)*newval);
		tree[node].prop+=newval;                        /// adding new value at child nodes
		return;
	}

	ll left = 2*node;
	ll right = (2*node)+1;
	ll mid = (begin+end)/2;

	update_query(left,begin,mid,lb,ub,newval);
	update_query(right,mid+1,end,lb,ub,newval);

	tree[node].val = tree[left].val + tree[right].val + (end-begin+1)*tree[node].prop;
}

int main()
{
	ll i,n,q;
	cout<<"enter how many numbers : ";
	cin>>n;

	for(i=1;i<=n;i++)
		cin>>a[i];

	init(1,1,n);

	cout<<"\nenter how many number for query(sum) : ";
	cin>>q;

	for(i=0;i<q;i++)
	{
		cout<<"\nenter lower and upper bound : ";
		ll lb,ub;
		cin>>lb>>ub;
		ll ans = sum_query(1,1,n,lb,ub,0);
		cout<<"Sum from "<<lb<<" to "<<ub<<" : "<<ans<<endl;
	}

	cout<<"\nenter how many number for query(update) : ";
	cin>>q;

	for(i=0;i<q;i++)
	{
		cout<<"\nenter lower bound, upper bound and value : ";
		ll lb,ub,newval;
		cin>>lb>>ub>>newval;
		update_query(1,1,n,lb,ub,newval);
	}

	cout<<"\nenter how many number for query(sum) after update : ";
	cin>>q;

	for(i=0;i<q;i++)
	{
		cout<<"\nenter lower and upper bound : ";
		ll lb,ub;
		cin>>lb>>ub;
		ll ans = sum_query(1,1,n,lb,ub,0);
		cout<<"Sum from "<<lb<<" to "<<ub<<" : "<<ans<<endl;
	}

	return 0;
}
