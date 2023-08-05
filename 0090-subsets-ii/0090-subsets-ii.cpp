class Solution {
private:
    void findSubsets(int index,vector<int> & nums, vector<int> current, 
                     vector<vector<int>> &ans){
        ans.emplace_back(current);
        for(int i=index;i<nums.size();i++){
            if(i > index && nums[i] == nums[i-1]) continue;
            current.emplace_back(nums[i]);
            findSubsets(i+1,nums,current,ans);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> current;
        vector<vector<int>>ans;
        findSubsets(0,nums,current,ans);
        return ans;
    }
};