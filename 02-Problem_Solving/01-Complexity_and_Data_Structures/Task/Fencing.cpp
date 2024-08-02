// Problem link: https://www.codechef.com/LRNDSA03/problems/FENCE?tab=statement
// Submission link: https://www.codechef.com/viewsolution/1076561085
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t,n,m,k,r,c,ret;
    cin>>t;
    set<pair<int,int>>st;
    while(t--){
        ret=0;
        cin>>n>>m>>k;
        for(int i=0;i<k;i++){
            cin>>r>>c;
            st.insert(make_pair(r,c));
        }
        for(auto it:st){
            int row=it.first;
            int col=it.second;
            if(st.find({row,col+1})==st.end()){
                ret++;
            }
            if(st.find({row,col-1})==st.end()){
                ret++;
            }
            if(st.find({row-1,col})==st.end()){
                ret++;
            }
            if(st.find({row+1,col})==st.end()){
                ret++;
            }
        }
        st.clear();
        cout<<ret<<endl;
    }

}
