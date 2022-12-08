class Solution {
    //solved by Understanding from a Tutorial
private:
    void findAllParenthesis(string current,int open,int close,vector<string>&result,int n){
        //When length of current string reaches to 2 * n push in to Answer
        if(current.length()==2*n){
            result.push_back(current);
            return;
        }
        //If Opening parenthesis are less than n then we can generate more parenthesis.
        if(open<n){
            findAllParenthesis(current+'(',open+1,close,result,n);
        }
        //if closing parenthesis are less than opening ones then we can generate more closing parenthesis.
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
