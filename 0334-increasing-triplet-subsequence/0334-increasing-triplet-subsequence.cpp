class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //Not the most Optimized
        int left=INT_MAX;
        int mid =INT_MAX;
        for(int i=0;i<nums.size();i++){
           if(nums[i]>mid){
               return true;
           }
            if(nums[i]>left && nums[i]<mid){
                mid=nums[i];
            }
            if(left>nums[i]){
                left=nums[i];
            }
        }
        return false;
    }
};