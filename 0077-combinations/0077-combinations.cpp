class Solution {
private:
    void findCombination(int start, int end,int &k,
                         vector<int> current, vector<vector<int>> &ans){
        if(current.size()==k){
            ans.emplace_back(current);
            return;
        }        
        for(int i = start;i<=end;i++){
            current.emplace_back(i);
            findCombination(i+1,end,k,current,ans);
            current.pop_back();
        }
    }    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        vector<vector<int>> ans;
        findCombination(1,n,k,current,ans);
        return ans;        
    }
};