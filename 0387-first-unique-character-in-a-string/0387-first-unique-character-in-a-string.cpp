class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map< char, pair< int,int > > map;
        
        for(int i = 0;i<s.length();i++){
            if (map.find(s[i]) == map.end()) {
                map[s[i]] = {1, i};
            } else {
                map[s[i]].first++;
            }
        }
        int ans = INT_MAX ;
        for(auto itr : map) 
            if(itr.second.first==1) 
                ans = min(ans, itr.second.second);
        
        return ans == INT_MAX ? -1 : ans ;
    }
};