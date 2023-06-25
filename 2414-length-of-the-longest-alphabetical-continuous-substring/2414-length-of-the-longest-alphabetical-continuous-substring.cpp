class Solution {
public:
    int longestContinuousSubstring(string s) {
        stack<char>st;
        stack<char>empty;
        int ans = -1 ;
        for(char ch : s){
            if(st.empty()){
                st.push(ch);
            }
            if(!st.empty() && int(st.top())+1 == int (ch)){
                st.push(ch);
            }
            else if( int(st.top())+1 != int(ch) ){
                int size = st.size();
                ans=max(ans,size);
                st=empty;
                st.push(ch);
            }
        }
        if(st.size() > ans) return st.size();
        return ans;
    }
};