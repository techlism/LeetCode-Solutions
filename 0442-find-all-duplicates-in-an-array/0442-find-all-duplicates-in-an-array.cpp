class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int freq=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                freq++;
            } 
            if(freq!=0){
                ans.push_back(nums[i+1]);
                freq=0;
            }
        }
        return ans;
    }
};