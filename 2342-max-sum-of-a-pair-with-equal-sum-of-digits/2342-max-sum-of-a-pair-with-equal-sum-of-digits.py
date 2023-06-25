from typing import List
class Solution:
    @staticmethod
    def digitSum(num:int):
        sum=0
        n=num
        while(n>0):
            sum = sum + n%10
            n = n//10
        return sum
    
    def maximumSum(self, nums: List[int]) -> int:
        maxSum=-1
        maxNumbyDigitSum = {}
        for num in nums:
            dsum = Solution.digitSum(num)
            if(dsum in maxNumbyDigitSum):
                maxSum=max(maxSum,num+maxNumbyDigitSum[dsum])
            #for the map it accepts two value (a default to be returned if nothing found)
            maxNumbyDigitSum[dsum]=max(num,maxNumbyDigitSum.get(dsum,0))
        
        return maxSum
            