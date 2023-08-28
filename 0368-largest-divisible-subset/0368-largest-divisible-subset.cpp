class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
sort(nums.begin(), nums.end());
    int n = nums.size();
    
    vector<int> dp(n, 1); // Initialize DP array with 1 since each number is a valid subset itself
    vector<int> prevIndex(n, -1); // To keep track of the previous index for constructing the subset
    
    int maxSize = 1, maxIndex = 0;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prevIndex[i] = j;
            }
        }
        if (dp[i] > maxSize) {
            maxSize = dp[i];
            maxIndex = i;
        }
    }
    
    vector<int> result;
    while (maxIndex != -1) {
        result.push_back(nums[maxIndex]);
        maxIndex = prevIndex[maxIndex];
    }
    
    return result;        
    }
};