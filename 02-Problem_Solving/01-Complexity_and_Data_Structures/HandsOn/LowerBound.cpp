//https://www.hackerrank.com/challenges/cpp-lower-bound/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size,x;
    cin>>size;
    vector<int>vec;
    for(int i=0;i<size;i++){
        cin>>x;
        vec.push_back(x);
    }
    cin>>x;
    int value;
    int index;
    while(x--){
        cin>>value;
        auto it=lower_bound(vec.begin(),vec.end(),value);
        index=it-vec.begin();
        if(vec[index]==value){
            cout<<"Yes "<<++index<<endl;
        }
        else{
            cout<<"No "<<++index<<endl;
        }
    }
    return 0;
}
