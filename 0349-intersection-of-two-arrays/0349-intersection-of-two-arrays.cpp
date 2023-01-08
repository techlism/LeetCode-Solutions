class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end()); // nlogn
        sort(nums2.begin(), nums2.end()); // nlogn
        
        int i = 0,j = 0;
        int m = nums1.size();
        int n = nums2.size();
        
        vector<int> res;
        
        while(i<m && j<n){
            if(i>0 &&  nums1[i-1] == nums1[i]){
                /*if we have already checked and traversed the nums[i-1] before and its same as previous.
                So we can skip this:*/
                //Most important thing that I was missing out
                i++;
                continue;
            }
            if(nums1[i] < nums2[j]){
                 i++;   
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{ 
            // If we found intersecting/common elements(Our Answer)
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};