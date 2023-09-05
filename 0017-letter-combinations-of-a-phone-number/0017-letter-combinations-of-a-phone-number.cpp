class Solution {
private:
    void solve(string &digits,string current,int index,vector<string> & ans,
               string mapping[]){
        if(index >= digits.length()){
            ans.emplace_back(current);
            return;
        }
        int number =  digits[index]-'0';
        string currMap = mapping[number];
        for(int i=0;i<currMap.length();i++){
            current.push_back(currMap[i]);
            solve(digits,current,index+1,ans,mapping);
            current.pop_back();
        }
    }
        
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        vector<string> ans;
        string current;
        int index = 0;
        // like vector<string>
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,current,index,ans,mapping);
        return ans;
    }
};