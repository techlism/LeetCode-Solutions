class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,string> inter;
        for(auto num : nums1){
            inter[num].push_back('a');
        }
        for(auto num : nums2){
            inter[num].push_back('b');
        }
        vector<vector<int>> ans(2,vector<int>());
        for(auto itr : inter){
            if(itr.second.find('a') != string::npos && itr.second.find('b') == string::npos)
                ans[0].emplace_back(itr.first);
            if(itr.second.find('a') == string::npos && itr.second.find('b') != string::npos)
                ans[1].emplace_back(itr.first);            
        }
        return ans;        
    }
};