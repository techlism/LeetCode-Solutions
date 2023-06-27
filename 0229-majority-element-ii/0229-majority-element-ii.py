class Solution:
    def majorityElement(self, nums):
        n = len(nums)
        numToFreq = dict()
        for num in nums:
            numToFreq[num] = numToFreq.get(num, 0) + 1
        
        ans = list()
        for num, freq in numToFreq.items():
            if freq > n // 3:
                ans.append(num)
        
        return ans
