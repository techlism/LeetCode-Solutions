class Solution:
    def fourSum(self, nums, target):
        nums.sort()
        ans = []
        unique = set()

        for i in range(len(nums) - 3):
            for j in range(i + 1, len(nums) - 2):
                front = j + 1
                back = len(nums) - 1

                while front < back:
                    current_sum = nums[i] + nums[j] + nums[front] + nums[back]
                    
                    if current_sum == target:
                        quadruplet = (nums[i], nums[j], nums[front], nums[back])
                        
                        if quadruplet not in unique:
                            ans.append(list(quadruplet))
                            unique.add(quadruplet)
                        
                        front += 1
                        back -= 1
                    
                    elif current_sum < target:
                        front += 1
                    
                    else:
                        back -= 1
        
        return ans
