import sys
sys.set_int_max_str_digits(0)
# python has a limit to convert a string to int which is 4300. code \U0001f446 removes the limit
class Solution:
    def divisibilityArray(self, word: str, m: int) -> List[int]:
        num=0
        ans=[]
        for i in word:
            num=num*10+int(i)
            if(num%m==0):
                ans+=[1]
            else:
                ans+=[0]
            num%=m # this is done to avoid TLE and it's logically right to shelve off some values that are not necessary
        return ans