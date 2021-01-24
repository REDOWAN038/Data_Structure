#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i,n,e,a,b,w,j,k;
	cout<<"Enter number of nodes ans edges : ";
	cin>>n>>e;
	cout<<endl;
	int dist[n][n];

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				dist[i][j] = 0;
			else
				dist[i][j] = 1000000;
		}
	}

	cout<<"Enter direct path and their weight : "<<endl;

	for(i=0;i<e;i++)
	{
		cin>>a>>b>>w;
		--a;
		--b;
		dist[a][b] = w;
	}

	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				dist[i][j] = min(dist[i][j],(dist[i][k]+dist[k][j]));
			}
		}
	}

	cout<<"All pair shortest path matrix : "<<endl;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<dist[i][j]<<" ";
		}

		cout<<endl;
	}

	return 0;
}
