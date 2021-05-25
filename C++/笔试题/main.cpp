#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;

    map<char, int> m;

    for(int i=0; i<s.length(); i++)
    {
        if(m.count(s[i]) == 0)
        {
            m.insert(pair<char, int>(s[i], 1));
        }
        else
        {
            m[s[i]]++;
        }
    }

    vector<int> v;
    for(map<char, int>::iterator it = m.begin(); it!=m.end(); it++)
    {
        v.push_back(it->second);
    }
    sort(v.begin(), v.end());


    int num = v.front();
    vector<char> c;
    for(map<char, int>::iterator it = m.begin(); it!=m.end(); it++)
    {
        if(it->second == num)
            c.push_back(it->first);
    }


    for(string::iterator it = s.begin(); it != s.end(); it++)
    {
        if(count(c.begin(), c.end(), *it) > 0)
        {
            s.erase(it);
            it--;
        }
    }

    cout << s << endl;
    
    return 0;
}