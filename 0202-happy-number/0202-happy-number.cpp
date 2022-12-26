class Solution {
private:
    int digitSquareSum(int n) {
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        if(fast == 1)
        return 1;
        fast = digitSquareSum(fast);
        if(fast == 1)
        return 1;
    } while(slow != fast);
     return 0;        
    }
};