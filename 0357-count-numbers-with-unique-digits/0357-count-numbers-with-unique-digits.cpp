class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n==0) return 1;
        int x = 9;
        int c = 9;
        for (int i=0;i<n-1;i++){
            x=x*c;
            c--;
        }        
        return countNumbersWithUniqueDigits(n-1) + x;
    }
};