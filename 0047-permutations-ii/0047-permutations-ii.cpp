class Solution {
private:
    void permutation(vector<int> nums, vector<vector<int>>& ans, int index){
        if(index >= nums.size()){
            ans.emplace_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++){
            if (i > index && (nums[i] == nums[index]))
                continue;
            swap(nums[i],nums[index]);
            permutation(nums,ans,index+1);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        permutation(nums,ans,0);
        return ans;
    }
};
