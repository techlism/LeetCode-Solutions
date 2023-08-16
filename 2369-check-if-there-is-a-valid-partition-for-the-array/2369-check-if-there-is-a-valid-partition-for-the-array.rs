class Solution:
    def checkPartitions(self, nums, dp,i) -> bool:
        if i==len(nums) : 
            return True;
        if i in dp: 
            return dp[i]
        
        result  = False
        
        if (i < len(nums) - 1 and nums[i]==nums[i+1]):
            result = self.checkPartitions(nums,dp,i+2)
        if i < len(nums) - 2 :
            if (nums [i] == nums[i+1] == nums[i+2] or
                nums[i]+1 ==nums[i+1] == nums[i+2]-1):
                result = result or self.checkPartitions(nums,dp,i+3)
        
        dp[i] = result
        return result        
    def validPartition(self, nums: List[int]) -> bool:
        dp={}
        return self.checkPartitions(nums,dp,0)