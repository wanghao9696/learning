#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> mergeVector(vector<int> &l, vector<int> &r)
{
    vector<int> m;
    while(l.size()>0 && r.size()>0)
    {
        if(l[0] < r[0])
        {
            m.push_back(l[0]);
            l.erase(l.begin());
        }
        if(r[0] < l[0])
        {
            m.push_back(r[0]);
            r.erase(r.begin());
        }
    }
    if(l.size()>0)
    {
        m.push_back(l[0]);
    }
    if(r.size()>0)
    {
        m.push_back(r[0]);
    }

    return m;
}


void mergeSort(vector<int> &v)
{
    if(v.size() <= 1)
    {
        return;
    }

    int mid = v.size() / 2;
    vector<int> l;
    vector<int> r;

    for(int i=0; i<mid; i++)
    {
        l.push_back(i);
    }
    for(int i=mid; i<v.size(); i++)
    {
        r.push_back(i);
    }
    mergeSort(l);
    mergeSort(r);
    mergeVector(l, r);
}


int main()
{
    vector<int> v;

    for(int i=10; i>0; i--)
    {
        v.push_back(i);
    }

    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << endl;

    vector<int> v2;
    mergeSort(v);

    for(int i=0; i<v2.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << endl;

    return 0;
}