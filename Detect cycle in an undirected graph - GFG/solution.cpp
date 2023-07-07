class Solution{
  private:
  bool dfs(int node,int parent,vector<bool> &  visited ,vector<int> adj[]){
      visited[node]=true;
      for(int adjNode : adj[node]){
          if(!visited[adjNode]){
              if(dfs(adjNode, node, visited,adj)) return true;
          }
          // It is not visited and it is also not a parent. Then there is a cycle
          else if(adjNode != parent) return true;
      }
      return false;
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool cycle = dfs(i,-1,visited,adj);
                if(cycle) return true;
            }
        }
        return false;
    }
};
