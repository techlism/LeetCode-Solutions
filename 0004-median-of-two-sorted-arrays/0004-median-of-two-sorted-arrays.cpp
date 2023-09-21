class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merged(nums1.size()+nums2.size());
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),merged.begin());
        sort(merged.begin(),merged.end());
        double median=0, two=2;
        int index1= (merged.size()-2)/2 ;
        int index2=merged.size()/2;
        if(merged.size() % 2==0){
            median = (merged[index1] + merged[index2])/two;
                   return median;
        }
        else{
            median=merged[index2];
                   return median;
        }
 
    }
};