class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string temp="";
    
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                //If there's no space then do word formation
                temp.push_back(s[i]);
            }
            else{
                //If space found and our temporary string is not empty then
                if(!temp.empty()){
                    st.push(temp);
                    //The space we are pushing should not be leading one
                    if(!st.empty())
                        st.push(" ");                   
                }
                temp=""; 
            }
        }
        st.push(temp);
        temp="";
        //Append uses less memory
        while(!st.empty()){
            //Checking if any leading space is pushed into the stack if yes then skip them
            if((st.top()[0])==' ' && temp.length()==0){
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