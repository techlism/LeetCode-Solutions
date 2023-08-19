// class Solution {
// private:
//     int solve1(vector<int>&nums ,vector<int>&dp , int index){
//         if(index == 0) return nums[0];
//         if (index < 0) return 0;
//         if (dp[index] != -1) return dp[index];
//         int pick = nums[index] + solve1(nums,dp,index-2);
//         int notpick = solve1(nums,dp,index-1);
//         dp[index]=max(pick,notpick);
//         return dp[index];
//     }
//     int solve2(vector<int>&nums ,vector<int>&dp , int index){
//         if(index <= 0) return 0;
//         if (dp[index] != -1) return dp[index];
//         int pick = nums[index] + solve2(nums,dp,index-2);
//         int notpick = solve2(nums,dp,index-1);
//         dp[index]=max(pick,notpick);
//         return dp[index];
//     }    
// public:
//     int rob(vector<int>& nums) {
//         if (nums.size()==1) return nums[0];
//         vector<int> dp1 (nums.size(),-1);
//         vector<int> dp2 (nums.size(),-1);
//         return max(solve1(nums,dp1,nums.size()-2),solve2(nums,dp2,nums.size()-1));
//     }
// };

class Solution{
private:
    int solve(vector<int> &nums,int s,int e){
        int prev = nums[s];
        int prev2 = 0;
        for(int i = s+1;i<=e;i++){
            int pick = nums[i];
            if (i > 1) pick+=prev2;
            int notpick = prev;
            prev2 = prev;
            prev=max(pick,notpick);
        }
        return prev;
    }
public:
    int rob(vector<int>&nums){
        if (nums.size()==1) return nums[0] ;
        return max(solve(nums,0,nums.size()-2),solve(nums,1,nums.size()-1));
    }    
};