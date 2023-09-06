class Solution {
private:
    void prepareAdj(unordered_map<int,list<int>> &adjList,vector<vector<int>>&edges){
        for(auto edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return;
    }
    void dfs(int n,unordered_map<int,list<int>>&adjList,vector<bool>&visited,
             set<int> &curr){
        visited[n]=true;
        curr.insert(n);
        for(auto node : adjList[n]){
            if(!visited[node]) dfs(node,adjList,visited,curr);
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,list<int>> adjList;
        prepareAdj(adjList,edges);
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){            
            if(!visited[i]){
                set<int> curr;
                dfs(i,adjList,visited,curr);
                if(curr.find(source) != curr.end() && curr.find(destination)!= curr.end())
                    return true;
            } 
        }
        return false;
    }
};