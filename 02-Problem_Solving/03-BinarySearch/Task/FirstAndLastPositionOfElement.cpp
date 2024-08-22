//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left <= right){
            int mid=left+(right-left)/2;
            if(nums[mid] == target){
                int first=mid;
                int last=mid;
                while(first >= 0 && nums[first]==target){
                    first--;
                }
                while(last < nums.size() && nums[last]==target){
                    last++;
                }
                return {first+1,last-1};
            }
            else if(nums[mid] > target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return {-1,-1};
    }
};