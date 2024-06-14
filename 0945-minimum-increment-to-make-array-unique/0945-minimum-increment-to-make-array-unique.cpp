class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int increment = 0;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                int increase = nums[i-1] + 1 - nums[i]; // this is the crux (still need to understand)
                increment += increase;
                nums[i] = nums[i-1] + 1; // increase the current element by 1
            }
        }
        return increment;
    }
};