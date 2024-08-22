//https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/
class Solution {
public:
    bool isPalindrom(const string& s){
        int left=0;
        int right=s.size()-1;
        while(left < right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
    return true;
    }
    void backtrack(const string& s, string s1, string s2,int idx,int& maxAnswer){
        if(idx >= s.size()){
            if(isPalindrom(s1) && isPalindrom(s2)){
                int ans=s1.size()*s2.size();
                maxAnswer=max(maxAnswer,ans);
            }
            return;
        }
        backtrack(s, s1+s[idx], s2 , idx+1, maxAnswer);
        backtrack(s, s1 , s2+s[idx] , idx+1 ,maxAnswer);
        backtrack(s, s1 ,s2 ,idx+1 , maxAnswer);
        
    }
    int maxProduct(string s) {
        int maxAnswer=INT_MIN;
        backtrack(s,"","",0,maxAnswer);
        return maxAnswer;
    }
};