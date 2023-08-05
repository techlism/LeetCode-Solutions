class Solution {
private:
    void findCombination(int start, int end, int target,int &k,
                         vector<int> current, vector<vector<int>> &ans){
        if(target==0 && current.size()==k){
            ans.emplace_back(current);
            return;
        }        
        for(int i = start;i<=end;i++){
            current.emplace_back(i);
            findCombination(i+1,end,target-i,k,current,ans);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> current;
        vector<vector<int>> ans;
        findCombination(1,9,n,k,current,ans);
        return ans;
    }
};