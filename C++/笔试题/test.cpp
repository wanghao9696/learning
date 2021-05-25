#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    vector<string> v;
    
    stringstream ss;
    ss << str;
    string a;
    while(getline(ss, a, ';'))
    {
        v.push_back(a);
    }
    string s = v.front();
    string t = v.back();

    vector<int> vs;
    vector<int> vt;
    
    for(int i=1; i<s.length()+1; i++)
    {
        string temp = s.substr(0, i);
        int num = count(temp.begin(), temp.end(), temp.back());
        vs.push_back(num);
    }
    for(int i=1; i<t.length()+1; i++)
    {
        string temp = t.substr(0, i);
        int num = count(temp.begin(), temp.end(), temp.back());
        vt.push_back(num);
    }

    bool ret = true;
    for(int i=0; i<vs.size(); i++)
    {
        if(vs[i] != vt[i])
            ret = false;
    }

    if(ret)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}