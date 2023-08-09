class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map< char, pair< int,set<int> > > map;
        for(int i = 0;i<s.length();i++){
            map[s[i]].first++;
            map[s[i]].second.insert(i);
        }
        int ans = INT_MAX ;
        for(auto itr : map){
            if(itr.second.first==1){
                ans=min(ans,*itr.second.second.begin());
            } 
        }
        return ans == INT_MAX ? -1 : ans ;
    }
};