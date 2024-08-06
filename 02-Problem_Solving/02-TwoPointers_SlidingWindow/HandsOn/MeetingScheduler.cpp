#include <bits/stdc++.h>
using namespace std;
vector <int>minAvailableDuration(vector<vector<int>>& slots1,vector<vector<int>>&nums2,int duration){
    sort(slots1.begin(),slots1.end());
    sort(slots2.begin(),slots2.end());
    int i=0;
    int j=0;
    while(i<slots1.size() && j<slots2.size()){
        int str1=slots1[i][0];
        int end1=slots1[i][1];
        int str2=slots2[j][0];
        int end2=slots2[j][1];
        if(min(end1,end2)-max(str1,str2)>=duration){
            return {max(str1,str2),max(str1,str2)+duration};
        }
        else if(end1>end2){
            j++;
        }
        else{
            i++;
        }
    }
    return {};
}