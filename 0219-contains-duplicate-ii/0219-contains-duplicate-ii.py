class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        dic = dict()
        for i, v in enumerate(nums):
            if v in dic and i - dic[v] <= k:
                return True
            dic[v] = i
        return False