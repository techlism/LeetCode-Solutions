class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        while(mid <= high){
            switch (nums[mid]){
                case 0 : 
                    swap(nums[low],nums[mid]);
                    low += 1;
                    mid += 1;
                    continue;
                case 1 :
                    mid += 1;
                    continue;
                case 2 :
                    swap(nums[mid],nums[high]);
                    high -= 1;
                    continue;
            }
        }
        return;
    }
};