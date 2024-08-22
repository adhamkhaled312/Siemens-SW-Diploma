//https://leetcode.com/problems/minimum-size-subarray-sum/description/
class Solution {
public:
int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;
    int right = 0;
    int sum = 0;
    int ret = INT_MAX;
    while (right < nums.size()) {
        sum += nums[right];
        while (sum >= target) {
            ret = min(ret, right - left + 1); 
            sum -= nums[left];
            left++;
        }
        right++;
    }
    return (ret == INT_MAX) ? 0 : ret;
}
};
