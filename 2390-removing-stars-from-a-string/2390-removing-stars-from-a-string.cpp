class Solution {
public:
    string removeStars(string st) {
        stack<char>s;
        for(auto i:st ){
            if(i=='*'&&!s.empty()){
                s.pop();
            }
            else{
                s.push(i);
            }
        }
        string ans;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};