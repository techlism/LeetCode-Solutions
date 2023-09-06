// #define vector<vector<int>>  v
class Solution {
private:
    void dfs(vector<vector<int>> & ans,vector<vector<int>> & graph , vector<int> currPath, int node){
        currPath.emplace_back(node);
        if(node==graph.size()-1){
            ans.emplace_back(currPath);
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
        vector<vector<int>> ans;
        vector<int> currPath;
        dfs(ans,graph,currPath,0);
        return ans;
    }
};