class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        intervals = sorted(zip(startTime,endTime,profit))
        dp = {}
        def dfs(i):
            if i==len(intervals) : return 0
            if i in dp : return dp[i]
            # don't include            
            res = dfs(i+1)
            #include
            j = bisect.bisect(intervals,(intervals[i][1],-1,1)) 
            # A built in tool for Binary Search, see C++ code for better understanding \U0001f446
            dp[i] = max(res,intervals[i][2]+dfs(j))
            return dp[i]
        return dfs(0)            