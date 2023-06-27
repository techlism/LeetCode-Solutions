class Solution:
#-------------------------------------------------#        
    # def intersect(self,word1,word2):
    #     set1=set(list(word1)) 
    #     set2 = set(list(word2))
    #     return set1.intersection(set2) 
    # This brings additional complexity if length of sets is larger
#-------------------------------------------------#    
    def maxProduct(self, words: List[str]) -> int:
        # ans = 0
        # for i in range(len(words)):
        #     for j in range(i+1,len(words)):
        #         common=self.intersect(words[i],words[j])
        #         if(len(common)==0):
        #             pdt=len(words[i]) * len(words[j])
        #             ans=max(ans,pdt)        
        # return ans 
        # \U0001f446 The solution was absolutely right but not efficient enough
#-----------------------------------------------------------------#        
        # We are re solving using bitmasking - Learnt through Luv's YT
        
        n=len(words)
        masks=[0] * n
        ans = 0
        for i in range(n):
            bitmask = 0
            for ch in words[i]:
                bit = 1 << (ord(ch) - ord('a')) # left shifting by 1
                bitmask = bitmask | bit
            masks[i] = bitmask
        for i in range(n):
            for j in range(i+1,n):
                if(masks[i] & masks[j]==0): # No Common Word
                    ans=max(ans,len(words[i])*len(words[j]))
        return ans            
        