#include <iostream>
#include <vector>
using namespace std;

void inserting_val(vector <int> &heap,int child)
{
    int parent = child/2;       /// parent_root_index  = child_root_index/2

    while(heap[parent]<heap[child] && parent>0)
    {
        swap(heap[parent],heap[child]);
        child = parent;
        parent = child/2;
    }
}

void rearrange(vector <int> &heap)
{
    int n = heap.size();
    int parent = 1;
    int max_val_idx = 1;        /// maximum value index of a tree left or right child
    int left,right;

    while(max_val_idx<=n && heap[parent]<=heap[max_val_idx])
    {
        swap(heap[max_val_idx],heap[parent]);
        parent = max_val_idx;
        left = (2*max_val_idx);     /// left child of parent
        right = (2*max_val_idx)+1;      /// right child of parent

        if(heap[left]>heap[right])
            max_val_idx = left;
        else
            max_val_idx = right;
    }
}

int main()
{
    int n;      /// array size
    cin>>n;
    vector <int> heap(n+1);
    heap[0] = -1;

    for(int i=1; i<=n; i++)
    {
        cin>>heap[i];
        inserting_val(heap,i);
    }

    /// printing heap

    cout<<"Heap Sort : ";

    while(heap.size()>1)
    {
        cout<<heap[1]<<" ";        /// printing root value
        swap(heap[1],heap[heap.size()]);     /// taking root value to the last position

        auto it = heap.end();
        it--;
        heap.erase(it);        /// deleting root value

        rearrange(heap);       /// rearrange the heap after deleting root
    }
}
