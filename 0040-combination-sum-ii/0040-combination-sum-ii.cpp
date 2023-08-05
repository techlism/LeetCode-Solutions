class Solution {
private :
    void findCombination(int index, vector<int> & candidates, int target,
                         vector<int> & current, vector<vector<int>> & ans){
        
        if(target==0){
            ans.emplace_back(current);
            return;
        }
        if(target < 0 || index >= candidates.size()) return;
        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i]==candidates[i-1]) continue;
            if(target >= candidates[i]){
                current.emplace_back(candidates[i]);
                findCombination(i+1,candidates,target-candidates[i],current,ans);
                current.pop_back();                
            }
            else return;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) { 
        vector <vector<int>> ans;
        vector <int> current;
        sort(candidates.begin(),candidates.end());
        findCombination(0,candidates,target,current,ans);
        return ans;
    }
};