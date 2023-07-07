class Solution{
public:
    void dfsUtil(int v, vector<bool>& visited, vector<int>& output, vector<int> adj[]) {
        visited[v] = true;
        output.push_back(v);
    
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited, output, adj);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<int> output;
    
        for (int v = 0; v < V; ++v) {
            if (!visited[v]) {
                dfsUtil(v, visited, output, adj);
            }
        }
    
        return output;
    }
};
