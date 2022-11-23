class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>ans1;
        vector<int>ans2;
        int len=max(s.length(),t.length());
        for(int i=0;i<len;i++){
            ans1.push_back(s[i]);
            ans2.push_back(t[i]);
        }
        // if(ans1.size()!=ans2.size()){
        //     return false;
        // }
        sort(ans1.begin(),ans1.end());
        sort(ans2.begin(),ans2.end());
        for(int i=0;i<ans2.size();i++){
            if(ans1[i]!=ans2[i]){
                return false;
            }
        }
        return true;
    }
};