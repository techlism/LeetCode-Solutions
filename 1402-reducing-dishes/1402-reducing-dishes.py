class Solution(object):
    def maxSatisfaction(self, satisfaction):
        """
        :type satisfaction: List[int]
        :rtype: int
        """
        satisfaction.sort(reverse=True)
        total_sum, current_sum = 0, 0
        for i in satisfaction:
            current_sum += i
            if current_sum < 0:
                break
            total_sum += current_sum
        return total_sum    
        