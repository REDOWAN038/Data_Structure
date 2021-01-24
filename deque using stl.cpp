#include<bits/stdc++.h>
using namespace std;
int main()
{
	deque <int> dq;
	deque <int> :: iterator it;

	dq.push_back(8);
	dq.push_front(9);
	dq.push_back(82);
	dq.push_back(3);
	dq.push_front(8);
	dq.push_back(81);

	cout<<dq.front()<<endl;
	cout<<dq.back()<<endl;
	cout<<dq.size()<<endl;

	for(it=dq.begin();it<dq.end();it++)
		cout<<*it<<endl;
}