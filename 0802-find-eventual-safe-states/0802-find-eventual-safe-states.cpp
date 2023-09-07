class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n);
        vector<vector<int>> graphRev(n);
        for(int i=0;i<n;i++){
            for(auto node : graph[i]){
                graphRev[node].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto neigh : graphRev[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    
};