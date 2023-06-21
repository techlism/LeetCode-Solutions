class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        ans=0
        for i in range(len(nums)):
            for j in range(len(nums)):
                if(abs(nums[j]-nums[i]==k)): ans+=1
        return ans