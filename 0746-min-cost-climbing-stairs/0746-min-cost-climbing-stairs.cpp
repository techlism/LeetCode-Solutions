class Solution {
private:
    int solve(vector<int>&cost , int index,vector<int>&dp){
        if( index== 0 || index == 1) return cost[index];
        if(index < 0) return 0;
        if (dp[index]!=-1) return dp[index];
        return dp[index]= cost[index] +
            min(solve(cost,index-1,dp),solve(cost,index-2,dp));
        
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        return min(solve(cost,cost.size()-1,dp),solve(cost,cost.size()-2,dp));
    }
};