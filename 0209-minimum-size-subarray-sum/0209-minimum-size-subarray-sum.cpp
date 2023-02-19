class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0;
        int e = 0;
        int sum=0; 
        int ans = INT_MAX;
        while (e < nums.size()) {
            sum += nums[e++];
            while (sum >= target) {
                ans = min(ans, e - s);
                sum -= nums[s++];
            }
        }
        return ans == INT_MAX ? 0 : ans;    
        //Sliding window
        //T.C. O(N)
    }
};