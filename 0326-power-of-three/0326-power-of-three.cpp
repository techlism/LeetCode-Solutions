class Solution {
public:
    bool isPowerOfThree(int n) {
    
        if(n==1){
            return true;
        }
        long a=3;
        while(a<=n){
         if(a==n){
                return true;
          }
          a=(a<<1)+a;
        }
         return false; 
    
    }
};