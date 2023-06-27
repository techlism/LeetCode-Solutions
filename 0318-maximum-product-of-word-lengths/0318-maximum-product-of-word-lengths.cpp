class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        vector<int>masks(words.size());
        for(int i = 0; i < words.size();i++){
            for(char ch : words[i]){
                masks[i] |= 1 << (ch - 'a');
            }
        }
        
        for(int i = 0; i<words.size();i++){
            for(int j = i+1; j<words.size();j++){
                if((masks[i] & masks[j] )== 0){
                    int len = words[i].length() * words[j].length();
                    ans = max(ans,len);
                }
            }
        }
        return ans;
    }
};