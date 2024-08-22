//https://leetcode.com/problems/numbers-with-same-consecutive-differences/description/
class Solution {
public:
    void backtrack(int n,int k, string now, int lastDigit , vector<int>& ans){
        if(now.size()==n){
            ans.push_back(stoi(now));
            return;
        }
        for(int i=0;i<10;i++){
            if(abs(i-lastDigit)==k){
                now+=to_string(i);
                backtrack(n,k,now,i,ans);
                now.pop_back();
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            string now=to_string(i);
            backtrack(n,k,now,i,ans);
        }
        return ans;
    }
};