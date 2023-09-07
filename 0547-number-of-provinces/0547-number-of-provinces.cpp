class Solution {
private:
    void dfs(int node, unordered_map<int,bool> &visited,unordered_map<int,list<int>>&adjList){
        if(node!=-1) visited[node]=true;
        for(auto neigh : adjList[node]){
            if(neigh != -1 && !visited[neigh]) dfs(neigh,visited,adjList);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,list<int>> adjList;
        // Preparing adj list
        for(int i = 0;i<isConnected.size();i++){
            adjList[i].push_back(-1);
            for(int j=0;j<isConnected[0].size();j++){
                if(i!=j && isConnected[i][j]==1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        unordered_map<int,bool> visited;
        int ans=0 ;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                dfs(i,visited,adjList);
                ans+=1;
            }
        }
        return ans;
    }
};