#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector < pair <int,string> > v;
    v.push_back(make_pair(1,"Labib"));
    v.push_back(make_pair(2,"Saif"));
    v.push_back(make_pair(3,"Chinmoy"));

    for(int i=0;i<v.size();i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;

    return 0;
}
