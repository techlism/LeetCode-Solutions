class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        s=set()
        for i in range(len(nums)):
            s.add(nums[i])
        return len(s)!=len(nums)