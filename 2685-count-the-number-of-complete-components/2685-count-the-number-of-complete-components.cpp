class Solution {
private:
    void dfs(int node,vector<vector<int>> & graph,int & nodeCount, int &edgeCount, 
             vector<bool> &visited){
        visited[node] = true;
        edgeCount += graph[node].size();
        nodeCount+=1;
        for(auto neigh : graph[node]){
            if(!visited[neigh]) dfs(neigh,graph,nodeCount,edgeCount,visited);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        int ans = 0 ;
        for(int i=0;i<n;i++){
            int nodeCount = 0;
            int edgeCount = 0;
            if(!visited[i]) {
                dfs(i,graph,nodeCount,edgeCount,visited);
            // Main logic
                if(nodeCount * (nodeCount - 1) == edgeCount) 
                    ans+=1;                
            }

        }
        return ans;
    }
};