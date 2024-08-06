//https://leetcode.com/problems/two-sum/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int sum;
        vector<pair<int, int>> numWithIndices;
        for (int i = 0; i < nums.size(); ++i) {
            numWithIndices.push_back({nums[i], i});
        }
        sort(numWithIndices.begin(),numWithIndices.end());
        while(right>left){
            sum=numWithIndices[right].first+numWithIndices[left].first;
            if(sum>target){
                right--;
            }else if(sum<target){
                left++;
            }else{
                break;
            }
        }
        return {numWithIndices[left].second,numWithIndices[right].second};
    }
};
