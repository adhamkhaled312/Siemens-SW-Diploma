// https://www.codechef.com/LRNDSA03/problems/SAVKONO
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t,n,z,temp,ret=0;
    cin>>t;
    while(t--){
        priority_queue<int> pq;
        ret=0;
        cin>>n>>z;
        for(int i=0;i<n;i++){
            cin>>temp;
            pq.push(temp);
        }
        while(z>0 && pq.top()>0){
            temp=pq.top();
            pq.pop();
            z-=temp;
            pq.push(temp/2);
            ret++;
        }
        if(z>0){
            cout<<"Evacuate"<<endl;
        }
        else{
            cout<<ret<<endl;
        }
    }
}
