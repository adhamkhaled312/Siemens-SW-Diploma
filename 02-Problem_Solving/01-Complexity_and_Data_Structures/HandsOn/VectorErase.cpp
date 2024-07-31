// https://www.hackerrank.com/challenges/vector-erase/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int size,x,erase1,erase2;
    cin>>size;
    vector<int>vec;
    for(int i=0;i<size;i++){
        cin>>x;
        vec.push_back(x);
    }  
    cin>>erase1;
    erase1--;
    vec.erase(vec.begin()+erase1);
    cin>>erase1>>erase2;
    erase1--;erase2--;
    vec.erase(vec.begin()+erase1,vec.begin()+erase2);
    cout<<vec.size()<<endl;
    for(auto it : vec){
        cout<<it<<" ";
    }
    return 0;
}
