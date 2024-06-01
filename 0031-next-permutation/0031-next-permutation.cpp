class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Step 1 - find the dip
        int dip = -1 ;
        int n = nums.size() ;
        // the loop is running from n-2 because we are accessing i+1 (if run from n-1, i+1 give overflow)
        for(int i = n - 2; i>= 0 ;i--){
            if(nums[i + 1] > nums[i]){
                dip = i;
                break;
            }
        }
        // if no dip (basically descendingly increasing then it is last permuation so return 1st)
        if(dip == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // since the array till dip is increasing then first value  greater then dip will be the smallest
        for(int i = n - 1; i > dip; i--){
            if(nums[dip] < nums[i]){
                swap(nums[dip], nums[i]);
                break;
            }            
        }
        // we found a permutation but the value from dip + 1 to the last should be smallest (for just next)
        // So reverse it (since values dip + 1 to end are in descending order)
        reverse(nums.begin() + dip + 1, nums.end());
        return;
    }
};