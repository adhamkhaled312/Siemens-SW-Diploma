// https://www.hackerrank.com/challenges/cpp-maps/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int type,q,value;
    string key;
    map<string,int>mp;
    cin>>q;
    while(q--){
        cin>>type>>key;
        switch(type){
            case 1: {
                cin>>value;
                mp[key]+=value;
                break;
            }
            case 2: mp.erase(key);break;
            case 3: cout<<mp[key]<<endl;break;
        }
    }
    return 0;
}



