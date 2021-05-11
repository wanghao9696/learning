#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n, k, a;
    cin >> n;
    cin  >> k;
    
    vector<int> v;
    while(cin >> a)
    {
        v.push_back(a);
        if(cin.get() == '\n')
            break;
    }
    
    vector<int> res;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i] > k)
            res.push_back(i);
    }
    
    vector<int> sum;
    int b = 0;
    for(int i=1; i<res.size(); i++)
    {
        if(res[i] - res[i-1] == 1)
        {
            b += 1;
            sum.push_back(b);
        }
    }
    sort(sum.begin(), sum.end());
    int rel = sum.back();
    cout << rel << endl;
    
    return 0;
}