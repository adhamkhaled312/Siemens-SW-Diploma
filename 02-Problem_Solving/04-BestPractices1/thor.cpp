//https://codeforces.com/problemset/problem/705/C
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    deque<pair<int,int>> vec;
    unordered_map<int,unordered_set<int>>mp;

    int t,n,type,temp,time=1,count=0,readTillNow=1;
    cin>>n>>t;
    while(t--){
        cin>>type>>temp;
        if(type==1){
            count++;
            mp[temp].insert(time);
            vec.push_back(make_pair(temp,time));
            time++;
        }
        else if(type==2){
            count-=mp[temp].size();
            mp.erase(temp);
        }
        else{
            for(int i=readTillNow-1;i<temp;i++){
                int app=vec[i].first;
                int tm=vec[i].second;
                if(mp[app].find(tm)!=mp[app].end()){
                    mp[app].erase(tm);
                    count--;
                }
            }
            readTillNow=max(readTillNow,temp);
        }
        cout<<count<<endl;
    }
}