#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    string s;
    vector<string> vec;
    while(cin >> s){

        stringstream ss(s);
        string item;
        while(getline(ss,item,',')){
            vec.push_back(item);
        }
        sort(vec.begin(),vec.end());
        reverse(vec.begin(), vec.end());

        int a_1 = atoi(vec[4].c_str());
        int a_2 = atoi(vec[3].c_str());

        if(a_1 != 0)
        {
            vector<int> cha;
            for(int i=0; i<4; i++)
            {
                cha.push_back(atoi(vec[i].c_str()) - atoi(vec[i+1].c_str()));
            }
            if(count(cha.begin(),cha.end(),1) == 4)
            {
                cout << "So Lucky!" << endl;
            }
            else
            {
                cout << "Oh My God!" << endl;
            }
        }

        if(a_1 == 0 && a_2 != 0)
        {
            vector<int> cha;
            for(int i=0; i<3; i++)
            {
                cha.push_back(atoi(vec[i].c_str()) - atoi(vec[i+1].c_str()));
            }
            if(count(cha.begin(),cha.end(),1) == 2 && count(cha.begin(),cha.end(),2) == 1)
            {
                cout << "So Lucky!" << endl;
            }
            else
            {
                cout << "Oh My God!" << endl;
            }
        }

        if(a_1 == 0 && a_2 == 0)
        {
            vector<int> cha;
            for(int i=0; i<2; i++)
            {
                cha.push_back(atoi(vec[i].c_str()) - atoi(vec[i+1].c_str()));
            }
            cout <<  cha[0] << endl;
            cout <<  cha[1] << endl;
            if((cha[0] == 1 || cha[0] == 2) && (cha[1] == 1 || cha[1] == 2))
            {
                cout << "So Lucky!" << endl;
            }
            else
            {
                cout << "Oh My God!" << endl;
            }
        }
    }
      
    return 0;
}