//https://leetcode.com/problems/merge-intervals/
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::vector<std::vector<int>> returnResult;
        bool flag=false;
        sort(intervals.begin(),intervals.end());
        int left=intervals[0][0];
        int right=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=left && intervals[i][0]<=right){
                right=std::max(intervals[i][1],right);
            }
            else{
                returnResult.push_back({left,right});
                left=intervals[i][0];
                right=intervals[i][1];
            }
        }
        returnResult.push_back({left,right});
        return returnResult;
    }
};