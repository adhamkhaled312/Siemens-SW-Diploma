//https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/
#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_set<char>st;
        int left=0;
        int right=2;
        int count=0;
        while(right<s.size()){
            st.insert(s[left]);
            st.insert(s[left+1]);
            st.insert(s[right]);
            if(st.size()==3){
                count++;
            }
            st.erase(s[left]);
            st.erase(s[right]);
            left++;
            right++;
        }
        return count;
    }
};