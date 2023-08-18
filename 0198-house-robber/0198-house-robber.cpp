class Solution {
private:
    int solve(vector<int>&nums ,vector<int>&dp , int index){
        if(index == 0) return nums[0];
        if (index < 0) return 0;
        if (dp[index] != -1) return dp[index];
        int pick = nums[index] + solve(nums,dp,index-2);
        int notpick = solve(nums,dp,index-1);
        dp[index]=max(pick,notpick);
        return dp[index];
    }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,dp,nums.size()-1);
    }
};