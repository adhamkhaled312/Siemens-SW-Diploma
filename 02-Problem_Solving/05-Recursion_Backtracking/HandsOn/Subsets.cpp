//https://leetcode.com/problems/subsets/description/
class Solution {
public:

    void backtrack(vector<int>& nums,vector<vector<int>>& result,vector<int>& subset, int index ){
        if(index==nums.size()){
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        backtrack(nums,result,subset,index+1);
        subset.pop_back();
        backtrack(nums,result,subset,index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(nums,result,subset,0);
        return result;
    }
};