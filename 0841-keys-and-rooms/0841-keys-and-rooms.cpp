class Solution {
private:
    void dfs(vector<vector<int>> & rooms,int & count,int node,vector<bool> & visited){
        visited[node]=true;
        count+=1;
        for(auto neighbor : rooms[node]){
            if(!visited[neighbor]) dfs(rooms,count,neighbor,visited);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>visited(rooms.size(),false);
        int count=0;
        dfs(rooms,count,0,visited);
        if(count==rooms.size()) return true;
        return false;
    }
};