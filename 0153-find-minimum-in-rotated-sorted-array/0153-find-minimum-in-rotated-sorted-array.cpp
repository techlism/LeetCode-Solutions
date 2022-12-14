class Solution {
private:
    int getPivot(vector<int>nums){
        int s=0;
        int e = nums.size()-2;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return s;
    }
public:
    int findMin(vector<int>& nums) {
        int pivot = getPivot(nums);
        return min(nums[0],nums[pivot]);
    }
};