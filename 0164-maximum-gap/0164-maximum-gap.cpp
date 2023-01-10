class Solution {
public:
    int maximumGap(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        if(nums.size()<=1){
            return 0;
        }
        int diff=0;
        for(int i=1;i<nums.size();i++){
            diff=max(diff,(nums[i]-nums[i-1]));
        }
        return  diff;
    }
};