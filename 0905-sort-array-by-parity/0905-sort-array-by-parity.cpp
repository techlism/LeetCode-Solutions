class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        for(auto n : nums) if(n%2==0) ans.emplace_back(n);
        for(auto n : nums) if(n%2!=0) ans.emplace_back(n);
        return ans;
    }
};