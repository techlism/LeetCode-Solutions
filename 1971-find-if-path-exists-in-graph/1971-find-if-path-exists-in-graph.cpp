class Solution {
private:
    void dfs(int n,unordered_map<int,list<int>>&adjList,vector<bool>&visited,
             bool &dest,int & destination){
        visited[n]=true;
        if(n==destination) dest=true;
        for(auto node : adjList[n]){
            if(!visited[node]) dfs(node,adjList,visited,dest,destination);
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,list<int>> adjList;
        vector<bool> visited(n,false);
        bool dest = false;
        // Preparing adjacency list
        for(auto edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        dfs(source,adjList,visited,dest,destination);
        return dest;
    }
};