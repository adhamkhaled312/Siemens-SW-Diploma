//https://www.codechef.com/LRNDSA03/problems/CVOTE
#include <bits/stdc++.h>
using namespace std;

int main() {
	map<string,int>chefs;
	map<string,int>countries;
	map<string,string>pr;
	int n,m;
	cin>>n>>m;
    string ch;
    string c;
	while(n--){
	    cin>>ch>>c;
	    pr.insert(pair<string,string>(ch,c));
	}
    while(m--){
        cin>>ch;
        chefs[ch]++;
        countries[pr[ch]]++;
    }

    int max=0;
    string maxc;
    for(auto it:countries){
        if(it.second>max){
            max=it.second;
            maxc=it.first;
        }
    }
    cout<<maxc<<endl;
    max=0;
    for(auto it:chefs){
        if(it.second>max){
            max=it.second;
            maxc=it.first;
        }
    }
    cout<<maxc<<endl;

}
