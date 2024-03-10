class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,string> inter;
        for(auto num : nums1){
            inter[num].push_back('a');
        }
        for(auto num : nums2){
            inter[num].push_back('b');
        }
        vector<int> ans;
        for(auto itr : inter){
            if(itr.second.find('a') != string::npos && itr.second.find('b') != string::npos)
                ans.emplace_back(itr.first);
        }
        return ans;
    }
};