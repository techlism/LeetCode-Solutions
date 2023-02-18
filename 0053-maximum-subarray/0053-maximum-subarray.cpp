class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // It's solved using a algorithm called Kardane's Algorithm
        int maxm=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            maxm=max(sum,maxm);
            if(sum<0){
                sum=0;
            }
        }
        return maxm;
        
    }
};