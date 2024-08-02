// Problem link:https://www.codechef.com/LRNDSA03/problems/DPAIRS?tab=statement
// Submission link: https://www.codechef.com/viewsolution/1076557441
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,m,maxx=0,minn=0;
	cin>>n>>m;
	vector<long long>ns(n);
	vector<long long>ms(m);
	for(int i=0;i<n;i++){
	    cin>>ns[i];
        if(ns[maxx]<ns[i]){
            maxx=i;
        }
	}
    for(int i=0;i<m;i++){
        cin>>ms[i];
        if(ms[minn]>ms[i]){
            minn=i;
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<minn<<endl;
    }
    for(int i=0;i<m;i++){
        if(i==minn){
            continue;
        }
        cout<<maxx<<" "<<i<<endl;
    }


}

