class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        for(int i=0;i<s.size() - 1 ; i++){
            int ascii1 = int(s[i]);
            int ascii2 = int(s[i+1]);
            ans += abs(ascii1 - ascii2);
        }
        return ans;
    }
};