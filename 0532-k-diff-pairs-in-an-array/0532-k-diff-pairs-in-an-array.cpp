class Solution {
private:
    int binarySearch(vector<int> & nums,int key){
        int s = 0 ;
        int e = nums.size()-1;
        int mid = s + (e-s) / 2;
        while(s<=e){
            if(nums[mid]==key) return mid;
            else if (nums[mid] > key ) e = mid - 1 ;
            else s = mid + 1;
            mid = s + (e-s) / 2; 
        }
        return -1;
    }
public:
    int findPairs(vector<int>& nums, int k) {
        
        using pair = pair<int,int>;
        set<pair>s; // To maintain the uniqueness
        sort(nums.begin(),nums.end()); // Sorting (O(nlogn))
        
        for(int i=0;i<nums.size();i++){
            int i2 = binarySearch(nums,nums[i] + k);
            if(i2 != -1 && i!=i2) s.insert(make_pair(nums[i],nums[i2]));
        }
        
        return s.size();
    }
};