//https://leetcode.com/problems/longest-palindromic-substring/description/
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1){
            return s.substr(0,1);
        }
        if(s.size()==2){
            if(s[0]==s[1])
                return s;
            else 
                return s.substr(0,1);
        }
        vector<vector<bool>>isPal(s.size(),vector<bool>(s.size(),false));
        for(int i=0;i<s.size();i++){
            isPal[i][i]=true;
        }
        int maxL=0;
        int maxR=0;
        int maxLength=INT_MIN;
        for(int l=s.size()-2;l>=0;l--){
            for(int r=l+1;r<s.size();r++){
                if(s[l]==s[r] && (isPal[l+1][r-1] || r-l+1==2)){
                    isPal[l][r]=true;
                    if(r-l+1 > maxLength){
                        maxR=r;
                        maxL=l;
                        maxLength=r-l+1;
                    }
                }
            }
        }   
        string result= maxLength==INT_MIN ? s.substr(maxL,1) : s.substr(maxL,maxLength);
        return result;
    }
};
