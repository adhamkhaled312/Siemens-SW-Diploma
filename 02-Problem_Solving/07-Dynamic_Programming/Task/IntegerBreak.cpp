//https://leetcode.com/submissions/detail/1373648612/
class Solution {
public:
    int solve(int i,int n,vector<int> &nums,int cnt,vector<vector<int>> &dp)
    {
        if(n==0 && cnt>=2)
            return 1;
        if(i>=nums.size() || n<0)
            return 0;
        if(dp[i][n]!=-1)
           return dp[i][n];
        
        int take=0;
        if(nums[i]<=n)
            take=nums[i]*solve(i,n-nums[i],nums,cnt+1,dp);

        int nottake=solve(i+1,n,nums,cnt,dp);
        dp[i][n]=max(take,nottake);
        return dp[i][n];
    }
    int integerBreak(int n) {
        vector<int> nums;
        for(int i=1;i<=n;i++)
            nums.push_back(i);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,n,nums,0,dp);
    }
};
