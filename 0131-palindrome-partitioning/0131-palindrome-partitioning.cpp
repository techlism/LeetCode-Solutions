class Solution {
private:
    bool palindrome(int start,int end,string &s){
     while(start<=end){
         if (s[start++] != s[end--])
             return false;         
     }
     return true;
    }
    
    void createPartition(vector<string>&path, vector<vector<string>> &ans,
                         int index, string &s){
        
        if(index >= s.length()){
            ans.emplace_back(path);
            return;
        }        
        for(int i=index;i<s.length();i++){
            if(palindrome(index,i,s)){
                path.emplace_back(s.substr(index,i-index+1));
                createPartition(path,ans,i+1,s);
                path.pop_back();
            }    
        }        
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ans;
        createPartition(path,ans,0,s);
        return ans;
        
    }
};