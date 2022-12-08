class Solution {
private:
    void findAllParenthesis(string current,int open,int close,vector<string>&result,int n){
        if(current.length()==2*n){
            result.push_back(current);
            return;
        }
        if(open<n){
            findAllParenthesis(current+'(',open+1,close,result,n);
        }
        if(close<open){
            findAllParenthesis(current+')',open,close+1,result,n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        findAllParenthesis("(",1,0,result,n);
        return result;
    }
};