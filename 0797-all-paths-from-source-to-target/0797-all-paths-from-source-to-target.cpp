#define v vector<vector<int>>
class Solution {
private:
    void dfs(v & ans,v & graph , vector<int> currPath, int node){
        currPath.emplace_back(node);
        if(node==graph.size()-1){
            ans.emplace_back(currPath);
            return;
        }
        else{
            for(auto neigh : graph[node]){
                dfs(ans,graph,currPath,neigh);
            }
        }
        currPath.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        v ans;
        vector<int> currPath;
        dfs(ans,graph,currPath,0);
        return ans;
    }
};