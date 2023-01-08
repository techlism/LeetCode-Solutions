class Solution {
private:
    int getPivot(vector<int>nums){
        int s=0;
        int e = nums.size()-2;
        //Checking if initial Duplicates exist
        while(s<e+1 && nums[s]==nums[s+1]){
            s++;
        }
        //Similarly checking for duplicates in last
        while(e>=0 && nums[e]==nums[0]){
            //Changing equality to just greater than didn't worked out.
            //As the loop for finding pivot didn't executed.
            e--;
        }
        //There was an edge case where size of array was 2 in that case end will become -1 and will cause problems
        //So reupdated the value for e
        if(e==-1){
            e=nums.size()-2;
        }
        //Loop should be executed atleast once.
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
        int pivot=getPivot(nums);
        return min(nums[0],nums[pivot]);
    }
};
