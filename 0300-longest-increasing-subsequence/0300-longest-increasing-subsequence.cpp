class Solution {
private:
    int solve(vector<int> & nums,int curr,int prev){
        // Time Complexity - O(2^N) -- TLE
        if(curr >= nums.size()) return 0;
        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev]) take = 1 + solve(nums,curr+1,curr);   
        int notTake = solve(nums,curr+1,prev);
        return  max(take, notTake);
     }
    int solveMem(vector<int> & nums,int curr,int prev,vector<vector<int>> &dp){
        // Time Complexity - O(2^N) -- TLE
        if(curr >= nums.size()) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev]) 
            take = 1 + solveMem(nums,curr+1,curr,dp);   
        
        int notTake = solveMem(nums,curr+1,prev,dp);
        return dp[curr][prev+1] = max(take, notTake);
     }    
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size() + 1,-1));
        return solveMem(nums,0,-1,dp);    
    }
};