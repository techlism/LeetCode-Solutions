class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,unordered_set<int>>map;
        
        for(int i=0;i<strs.size();i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            map[str].insert(i);
        }
        vector<vector<string>> ans;
        for(auto s:map){
            vector<string> grp;
            for(auto i: s.second) grp.emplace_back(strs[i]);
            ans.emplace_back(grp);
        }
        return ans;
    }
};