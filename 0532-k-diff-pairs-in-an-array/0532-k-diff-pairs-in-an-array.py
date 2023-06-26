class Solution:
    def binarySearch(self, nums, key):
        left, right = 0, len(nums) - 1
        
        while left <= right:
            mid = left + (right - left) // 2
            
            if nums[mid] == key:
                return mid
            elif nums[mid] > key:
                right = mid - 1
            else:
                left = mid + 1
        
        return -1
#-------------------------------------------------#    
    def findPairs(self, nums, k):
        unique_pairs = set()
        nums.sort()
        
        for i in range(len(nums)):
            i2 = self.binarySearch(nums, nums[i] + k)
            if i2 != -1 and i != i2:
                unique_pairs.add((nums[i], nums[i2]))
        
        return len(unique_pairs)
