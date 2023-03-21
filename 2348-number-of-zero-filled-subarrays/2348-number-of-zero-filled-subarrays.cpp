class Solution {
private:
    long long sum(long long n){
        return (n*(n+1))>>1;
    }
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long n = 0;
        int prev = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(n==0){
                    n++;
                }
                else if(i-prev != 1){
                    count+=sum(n);
                    n=1;
                }
                else if(i-prev == 1){
                    n++;
                }
                prev=i;
            }
        }
        if(n){
            count+=sum(n);
        }
        return count;
    }
};