class Solution {
    // Solution is using pick not pick approach . Try to draw recursive tree
private:
    void findCombination(int ind, int target, vector<int> & arr , vector<vector<int>>&ans,vector<int> & ds){
        if(ind == arr.size()){
            if(target==0) ans.emplace_back(ds);
            return;
        }
        if(arr[ind] <= target){
            ds.emplace_back(arr[ind]);
            findCombination(ind,target-arr[ind],arr,ans,ds);
            ds.pop_back();
        }
        findCombination(ind+1,target,arr,ans,ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,target,candidates,ans,ds);
        return ans;
    }
};