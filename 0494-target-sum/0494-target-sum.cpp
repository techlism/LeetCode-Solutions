class Solution {
private:
    void countSum(vector<int>&nums, int target, int curr,int & count){
        if(curr >= nums.size()){
            if(target == 0) count+=1;
            return;
        }
        countSum(nums,target-nums[curr],curr+1,count);
        countSum(nums,target+nums[curr],curr+1,count);        
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0 ;
        countSum(nums,target,0,count);
        return count;
    }
};