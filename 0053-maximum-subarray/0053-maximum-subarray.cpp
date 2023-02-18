class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // It's solved using a algorithm called Kardane's Algorithm
        int maxm=nums[0];
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            maxm=max(sum,maxm);
            if(sum<0){
                sum=0;
            }
        }
        return maxm;        
    }
};