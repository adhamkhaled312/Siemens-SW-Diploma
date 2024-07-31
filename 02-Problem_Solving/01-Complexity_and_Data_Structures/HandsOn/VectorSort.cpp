//https://www.hackerrank.com/challenges/vector-sort/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,input;
    cin>>n;
    vector<int>vec;
    for(int i=0;i<n;i++){
        cin>>input;
        vec.push_back(input);
    }
    sort(vec.begin(),vec.end()); 
    for(auto it : vec){
        cout<<it<<" ";
    }
    return 0;
}
