class Solution {
private:
    int solve(int n, vector<int> & dp){
        
        if( n == 0 || n == 1) return 1;
        if( n == 2) return 2;
        if(dp[n]!=-1) return dp[n];
        dp[n] = solve(n-1,dp) + solve(n-2,dp);
        return dp[n];
    
    }
    int tab(int n)
    {
        int stair0 = 0;
        int stair1 = 1;
        for(int i =0;i<n;i++)
        {
            int next = stair0 + stair1;
            stair0 = stair1;
            stair1 = next;
        }
        return stair1;
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return tab(n);
        return solve(n,dp);
    }
};