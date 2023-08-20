class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n<2) return n;
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        int maxm=INT_MIN;
        for(int i= 2;i<=n;i++){
            if (i%2==0) dp[i]=dp[i/2];
            else dp[i] = dp[i/2] + dp[i/2 + 1];
            maxm=max(maxm,dp[i]);
        }
        return maxm;
    }
};