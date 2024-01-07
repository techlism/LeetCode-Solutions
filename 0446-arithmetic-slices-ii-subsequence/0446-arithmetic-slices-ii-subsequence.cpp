class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0; // Using long long to avoid overflow

        vector<unordered_map<long long, int>> dp(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = static_cast<long long>(nums[i]) - nums[j];
                dp[i][diff] += 1;

                // If there are arithmetic subsequences ending at j with the same diff,
                // update the count at i using those subsequences.
                if (dp[j].count(diff)) {
                    dp[i][diff] += dp[j][diff];
                    ans += dp[j][diff];
                }
            }
        }
        return static_cast<int>(ans);
        // Got the most part but missing some of the things like -- why no checking for under size etc
    }
};
