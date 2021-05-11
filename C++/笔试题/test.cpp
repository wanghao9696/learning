#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

bool isZhiShu(int n)
{
    if(n == 1)
        return true;
    else if(n == 2)
        return true;
    else
    {
        for(int i=2; i<n; i++)
        {
            if(n % i == 0)
                return false;
        }
        return true;
    }
}

int main()
{
    long long n;
    int num, min, max, m;
    string s, x, t;
    cin >> s;
    cin >> n;
	if(n == 1)
    {
        cout << "No" << endl;
        cout << 1 << endl;
    }
    x = s;
    for(int i=0; i<n; i++)
    {
        if(x.length() < n)
        {
            x += s;
        }
        else
            break;
    }
    for(int i=0; i<n; i++)
    {
        t += x[i];
    }
    // cout << t << endl;
    
    vector<char> str;
    vector<int> v;
    char a;
    num = 1;
    for(int i=0; i<t.length(); i++)
    {
        a = t[i];
        str.push_back(a);
    }
    for(int i=0; i<str.size(); i++)
    {
        int r = count(str.begin(), str.end(), str[i]);
        v.push_back(r);
    }
    sort(v.begin(), v.end());
    min = v.front();
    max = v.back();
    m = max - min;
    if(m == 0)
    {
        cout << "No" << endl;
        cout << 0 << endl;
    }
    else
    {
        bool ret = isZhiShu(m);
        if(ret)
        {
            cout << "Yes" << endl;
            cout << m << endl;
        }
        else
        {
            cout << "No" << endl;
            cout << m << endl;
        }
    }
    
    return 0;
}