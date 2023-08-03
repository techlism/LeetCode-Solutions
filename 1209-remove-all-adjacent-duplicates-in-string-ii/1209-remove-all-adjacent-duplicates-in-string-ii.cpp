class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(auto ch : s){
            if(st.empty()) st.push({ch,1});
            else{
                if(st.top().first == ch) st.top().second++ ;
                else st.push({ch,1}) ;
            }
            if(!st.empty() && st.top().second == k) st.pop();
        }
        string ans = "";
        while (!st.empty()) {
            char ch = st.top().first;
            int count = st.top().second;
            while (count > 0) {
                ans.insert(ans.begin(),ch);
                count--;
            }
            st.pop();
        }
        return ans;
    }
};