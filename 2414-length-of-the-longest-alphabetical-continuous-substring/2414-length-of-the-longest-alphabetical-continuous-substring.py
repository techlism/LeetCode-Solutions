class Solution:
    def longestContinuousSubstring(self, s):
        st = []
        empty = []
        ans = -1
        for ch in s:
            if len(st) == 0 or ( len(st) != 0 and ord(st[-1]) + 1 == ord(ch) ):
                st.append(ch)
            elif ord(st[-1]) + 1 != ord(ch):
                size = len(st)
                ans = max(ans, size)
                st = empty.copy()
                st.append(ch)
        return max(ans,len(st))
