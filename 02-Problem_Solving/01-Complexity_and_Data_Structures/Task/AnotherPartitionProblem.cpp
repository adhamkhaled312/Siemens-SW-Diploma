// Problem link: https://www.codechef.com/LRNDSA03/problems/EXUNC?tab=statement
// Submission link: https://www.codechef.com/viewsolution/1076770447
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here 
	long long n,q,temp,x,y;
	cin>>n>>q;
	vector<long long>vec(n+2);
    vec[0]=1e6+1;
    vec[n+1]=1e6+1;
    set<int>s;
    for(long long i=1;i<=n;i++){
        cin>>vec[i];
        if(vec[i]%vec[i-1]!=0){
            s.insert(i);
        }
    }
	while(q--){
        cin>>temp;
        if(temp==1){
            cin>>x>>y;
            vec[x]=y;
            if(vec[x]%vec[x-1]!=0){
                s.insert(x);
            }
            else{
                if(s.count(x)){
                    s.erase(x);
                }
            }
            if(vec[x+1]%vec[x]!=0){
                s.insert(x+1);
            }
            else{
                if(s.count(x+1)){
                    s.erase(x+1);
                }
            }
        }
        else{
            cin>>x;
            auto it=s.upper_bound(x);
            it--;
            cout<<*it<<endl;

        }
	}
}
