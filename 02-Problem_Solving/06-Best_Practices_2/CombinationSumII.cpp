//https://leetcode.com/problems/combination-sum-ii/description/
class Solution {
public:
    void backtrack(vector<int>& candidates,int idx,int target,vector<vector<int>>& results,vector<int>& vec){
        if(target==0){
            results.push_back(vec);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(target-candidates[i]<0){
                break;
            }
            if(i>idx && candidates[i]==candidates[i-1]){
                continue;
            }
            vec.push_back(candidates[i]);
            backtrack(candidates,i+1,target-candidates[i],results,vec);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int>vec;
        backtrack(candidates,0,target,ans,vec);
        return ans;
    }
};