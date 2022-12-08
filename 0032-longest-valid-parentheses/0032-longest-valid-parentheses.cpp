class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>index;
        index.push(-1);
        stack<char>st;
        int maxi=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
                index.push(i);
            }
            else{
                if(!st.empty() && s[i]==')' && st.top()=='('){
                    st.pop();
                    index.pop();
                    maxi=max(maxi,i-index.top());
                }
                else{
                    index.push(i);
                }
            }
        }
        return maxi;
    }
};