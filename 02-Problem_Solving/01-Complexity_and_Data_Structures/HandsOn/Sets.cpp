// https://www.hackerrank.com/challenges/cpp-sets/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int type,temp,x;
    cin>>x;
    set<int>s;
    while(x--){
        cin>>type;
        cin>>temp;
        switch (type) {
            case 1: s.insert(temp);break;
            case 2: s.erase(temp);break;
            case 3: auto it=s.find(temp);
                    if(it==s.end()){
                        cout<<"No\n";
                    }else{
                        cout<<"Yes\n";
                    }
                    break;
    }   
    }
    return 0;
}