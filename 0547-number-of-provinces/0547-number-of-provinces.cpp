class Solution {
private:
    void dfs(int node, unordered_map<int,bool> 
             &visited,unordered_map<int,list<int>>&adjList){
        if(node!=-1) visited[node]=true;
        for(auto neigh : adjList[node]){
            if(neigh != -1 && !visited[neigh]) dfs(neigh,visited,adjList);
        }
    }
    // Logic 2
    void dfs(int node, vector<vector<int>> & isConnected,unordered_map<int,bool> &visited){
        visited[node] = true;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node][i] && !visited[i]) dfs(i,isConnected,visited);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Logic 1 : Prepare an adjacencyList
        // Logic 2 : use the given adjacencyMatrix
        // unordered_map<int,list<int>> adjList;
        // // Preparing adj list
        // for(int i = 0;i<isConnected.size();i++){
        //     adjList[i].push_back(-1);
        //     for(int j=0;j<isConnected[0].size();j++){
        //         if(i!=j && isConnected[i][j]==1){
        //             adjList[i].push_back(j);
        //             adjList[j].push_back(i);
        //         }
        //     }
        // }
        unordered_map<int,bool> visited;
        int ans= 0 ;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                dfs(i,isConnected,visited);
                ans+=1;
            }
        }
        return ans;
    }
};