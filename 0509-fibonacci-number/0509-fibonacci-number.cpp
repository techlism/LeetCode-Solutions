class Solution {
private:
    int fibn(int n, vector<int> & dp){
        if(n==0)
         return 0;
        if(n==1)
         return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = fibn(n-2,dp) + fibn(n-1,dp);
    }
public:
    int fib(int n) {

        vector<int> dp(n+1,-1); 
        return fibn(n,dp);
    }
};