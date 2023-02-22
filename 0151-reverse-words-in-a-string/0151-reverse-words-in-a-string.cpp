class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string temp="";
    
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                temp.push_back(s[i]);
            }
            else{
                if(!temp.empty()){
                    st.push(temp);
                    if(!st.empty())
                        st.push(" ");                   
                }
                temp=""; 
            }
        }
        st.push(temp);
        temp="";
        while(!st.empty()){
            if(int(st.top()[0])==32 && temp.length()==0){
                st.pop();
            }
            else{
                temp.append(st.top());
                st.pop();                
            }
        }
        return temp;
    }
};