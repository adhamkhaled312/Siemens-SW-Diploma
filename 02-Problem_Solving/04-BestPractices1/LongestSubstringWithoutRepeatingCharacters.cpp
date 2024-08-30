//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1){
            return s.size();
        }
        unordered_map<char,int>freq;
        int ret=INT_MIN;
        int l=0;
        int r=0;
        freq[s[0]]++;
        while(r<s.size()-1){
            r++;
            freq[s[r]]++;
            if(freq[s[r]]>1){
                while(freq[s[r]]>1){
                    freq[s[l]]--;
                    l++;
                }
            }
            ret=max(ret,r-l+1);
        }
        return ret;
    }
};