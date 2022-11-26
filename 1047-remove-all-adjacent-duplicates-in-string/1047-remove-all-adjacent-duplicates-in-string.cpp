class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() &&  s[i]==st.top()){
               st.pop();
            }
            else{
               st.push(s[i]);
            } 
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
       }
       int e=ans.length()-1,i=0;
       while(i<=e){
            swap(ans[i++],ans[e--]);
       }
        return ans;   
    }
};