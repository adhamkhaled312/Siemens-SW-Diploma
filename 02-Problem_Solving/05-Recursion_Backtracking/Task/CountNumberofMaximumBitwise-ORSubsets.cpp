//https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
class Solution {
public:
    int calcOR(vector<int>& vec){
        int res=0;
        for(int i=0;i<vec.size();i++){
            res|=vec[i];
        }
        return res;
    }
    void backtrack(const vector<int>& nums, vector<int>& res, int max,int& count,int idx){
        if(calcOR(res)==max){
            count++;
        }
        for(int i=idx;i<nums.size();i++){
            res.push_back(nums[i]);
            backtrack(nums,res,max,count,i+1);
            res.pop_back();
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int count=0;
        vector<int>res;
        int max=calcOR(nums);
        backtrack(nums,res,max,count,0);
        return count;
    }
};