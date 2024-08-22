//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first=0;
        int second=numbers.size()-1;
        
        while(1){
            int sum=numbers[first]+numbers[second];
            if(sum==target){
                break;
            }
            else if(sum < target){
                first++;
            }
            else if(sum > target){
                second--;
            }
        }
        return {first+1,second+1};
    }
};
