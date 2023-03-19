class Solution {
public:
    string removeKdigits(string num, int k) {
       string ans = "";
       // this does use the functionality of stack but without mentioning explicitly
       for (char c : num) {
           while (ans.length() && ans.back() > c && k>0) {
               ans.pop_back();                                  
               k--;                                            
           }
           //for 0s in prefix
           if (ans.length() || c != '0') { 
               ans.push_back(c); 
           }  
       }
       
       while (ans.length() && k--){ 
           ans.pop_back(); 
       }         
       //if ans is empty return 0 else return ans
       return ans.empty() ? "0" : ans;        
    }
};