//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfsTraversal; // Resultant BFS traversal
        
        vector<bool> visited(V, false); // Array to keep track of visited vertices
        queue<int> q; // Queue for BFS traversal
        
        visited[0] = true; // Mark the starting vertex as visited
        q.push(0); // Enqueue the starting vertex
        
        while (!q.empty()) {
            int currVertex = q.front(); // Get the front vertex from the queue
            q.pop(); // Dequeue the front vertex
            
            bfsTraversal.push_back(currVertex); // Add the current vertex to the BFS traversal
            
            // Traverse the adjacency list of the current vertex
            for (int neighbor : adj[currVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true; // Mark the neighbor as visited
                    q.push(neighbor); // Enqueue the neighbor
                }
            }
        }
        
        return bfsTraversal;    
    
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends