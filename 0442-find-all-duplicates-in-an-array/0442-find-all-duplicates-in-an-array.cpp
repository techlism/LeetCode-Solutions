class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //Time Complexity  - O(NLogN)
        //Space Complexity - O(1) - excluding answer array
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int freq=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                freq++;
            } 
            if(freq!=0){
                ans.emplace_back(nums[i+1]);
                freq=0;
            }
        }
        return ans;
    }
};