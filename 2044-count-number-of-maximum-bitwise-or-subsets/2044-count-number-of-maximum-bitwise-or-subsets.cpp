class Solution {
private:
    void countOr(vector<int>&nums, vector<int>& results, int curr,int index){
        if(index >= nums.size()) {
            results.emplace_back(curr);
            return;
        }
        countOr(nums,results,curr,index+1);
        curr |= nums[index];
        countOr(nums,results,curr,index+1);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> results;
        countOr(nums,results,0,0);
        sort(results.begin(),results.end());
        int e = results.size() - 1;
        int ans = 1;
        while(e > 0 && results[e]==results[e-1]) {
            ans++;
            e--;
        }
        return ans;
    }
};