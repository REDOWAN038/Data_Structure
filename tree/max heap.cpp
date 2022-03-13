#include<bits/stdc++.h>
using namespace std;

void insert(vector <int> &heap,int child)
{
    int parent = child/2;


    while(heap[parent]<heap[child] && parent>0)
    {
        swap(heap[parent],heap[child]);
        child = parent;
        parent/=2;
    }

}

void heapify(vector <int> &heap)
{
    int n = heap.size();
    int parent = 1;
    int idx = 1;

    while(idx<n && heap[parent]<=heap[idx])
    {
        swap(heap[parent],heap[idx]);
        int left = 2*idx;
        int right = left+1;
        parent = idx;

        if(left>=n)
            break;
        else if(right>=n)
            idx = left;
        else
        {
            if(heap[left]>heap[right])
                idx = left;
            else
                idx = right;
        }
    }
}

void pop(vector <int> &heap)
{
    cout<<"Popped element : "<<heap[1]<<endl;
    int n = heap.size();
    swap(heap[1],heap[n-1]);
    heap.pop_back();
    heapify(heap);
}

int main()
{
    int n;
    cin>>n;
    vector <int> heap;

    heap.push_back(-1);

    for(int i=1; i<=n; i++)
    {
        int val;
        cin>>val;
        heap.push_back(val);
        insert(heap,i);
    }

    while(heap.size()>1)
    {
        pop(heap);
    }

    return 0;
}
