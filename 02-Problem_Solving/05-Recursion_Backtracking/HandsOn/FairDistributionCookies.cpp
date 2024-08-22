//https://leetcode.com/problems/fair-distribution-of-cookies/
class Solution {
public:
    void backtrack(const vector<int>& cookies, vector<int>& childCount, int cookiesIdx, int& minimumAns){
        if(cookiesIdx >= cookies.size() ){
            int ans=*max_element(childCount.begin(),childCount.end());
            minimumAns=min(minimumAns,ans);
            return;
        }
        for(int i=0;i<childCount.size();i++){
            childCount[i]+=cookies[cookiesIdx];
            backtrack(cookies,childCount,cookiesIdx+1,minimumAns);
            childCount[i]-=cookies[cookiesIdx];

        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int minimumAns=INT_MAX;
        vector<int> childCount(k,0);
        backtrack(cookies,childCount,0,minimumAns);
        return minimumAns;
    }
};