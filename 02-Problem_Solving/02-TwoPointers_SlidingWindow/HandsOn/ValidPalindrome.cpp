//https://leetcode.com/problems/valid-palindrome/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.size();){
            s[i]=tolower(s[i]);
            if( !(s[i]>='a' && s[i]<='z')|| !(s[i]>='0' && s[i]<='9') ){
                s.erase(i,1);
            }else{
                i++;
            }
        }
        int left=0;
        int right=s.size()-1;
        while(right>left){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
    return true;
    }
    
};