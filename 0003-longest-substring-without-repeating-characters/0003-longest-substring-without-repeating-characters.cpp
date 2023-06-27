class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int longest = 0;
        unordered_set<char> us;
        
        while(r < s.length()){
            if(us.find(s[r]) == us.end()){
                us.insert(s[r]);
                longest=max(longest,r-l+1);
                r++;
            }
            else{
                us.erase(s[l]);
                ++l;
            }
        }
        
        return longest;
    }
};