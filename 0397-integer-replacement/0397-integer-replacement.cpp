class Solution {
    int res=0;
public:
    int integerReplacement(int n) {
        if (n == 1)
            return res;
        if (n == 3){
            return res+=2;
        }
        if (n == INT_MAX)
            return 32;
        
        res ++;
        if (n & 1){  //n&1 means (n%2)
            if ((n + 1) % 4 == 0) // This gives the minimum steps
                integerReplacement(n + 1);
            else
                integerReplacement(n - 1);            
        }
        else
            integerReplacement(n / 2);
            
        return res;        
    }
};