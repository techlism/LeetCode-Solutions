class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int> numToFreq;
        for(auto num : nums){
            numToFreq[num]++;
        }
        vector<int>ans;
        for(auto itr : numToFreq){
            if(itr.second > (n/3) ) ans.emplace_back(itr.first);
        }
        return ans;
    }
};