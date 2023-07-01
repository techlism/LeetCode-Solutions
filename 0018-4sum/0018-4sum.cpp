class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long long target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;        
        for(int i = 0; i < nums.size(); i++) {
            // Avoid Duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            for(int j = i + 1; j < nums.size(); j++) {
                // Avoid Duplicates
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                int front = j + 1;
                int back = nums.size() - 1;
                
                while(front < back) {
                    // To avoid Int Overflow
                    long long sum = static_cast<long long>(nums[front]) + nums[back]; // Perform addition with long long
                    if (sum > target && (sum - target) > INT_MAX)
                        break; // No need to continue searching in this direction
                    if (sum < target && (target - sum) > INT_MAX)
                        break; // No need to continue searching in this direction
                    
                    long long currentSum = static_cast<long long>(nums[i]) + nums[j] + sum; // Perform addition with long long
                    
                    if (currentSum == target) {
                        ans.push_back({nums[i], nums[j], nums[front], nums[back]});
                        // Avoiding duplicate Quads
                        while(front < back && nums[front] == nums[front + 1])
                            front++;
                        while(front < back && nums[back] == nums[back - 1])
                            back--;
                        front++;
                        back--;
                    } 
                    else if (currentSum < target) {
                        front++;
                    } 
                    else {
                        back--;
                    }
                }
            }
        }
        
        return ans;
    }
};
