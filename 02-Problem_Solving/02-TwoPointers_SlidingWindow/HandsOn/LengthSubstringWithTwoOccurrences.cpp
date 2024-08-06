//https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int maximumLengthSubstring(string s) {
    int left = 0;
    int right = 0;
    int ret = 0;
    vector<int> freqArr(26, 0);

    while (right < s.size()) {
        freqArr[s[right] - 'a']++;
        while (freqArr[s[right] - 'a'] > 2) {
            freqArr[s[left] - 'a']--;
            left++;
        }
        ret = max(ret, right - left + 1);
        right++;
    }

    return ret;
}

};