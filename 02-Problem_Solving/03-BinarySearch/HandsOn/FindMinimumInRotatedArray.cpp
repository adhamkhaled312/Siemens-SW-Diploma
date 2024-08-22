//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int ret=INT_MAX;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid] >= nums[left]){
                ret=min(ret,nums[left]);
                left=mid+1;
            }
            else if(nums[mid] <= nums[right]){
                ret=min(ret,nums[mid]);
                right=mid-1;
            }
        }
        return ret;   
    }
};