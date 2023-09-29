class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> nums1 = nums;
        sort(nums1.begin(),nums1.end());
        vector<int> nums2 = nums;
        sort(nums2.begin(),nums2.end(),greater<int>());
        return nums==nums1 || nums==nums2;
    }
};