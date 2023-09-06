class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // use Kahn's Algo to understand better
        vector<bool> incomingEdgeExists(n,false);
        for(auto edge : edges) incomingEdgeExists[edge[1]] = true;
        vector<int> ans;
        for(int i=0;i<n;i++)
            if(!incomingEdgeExists[i]) ans.emplace_back(i);
        return ans;
    }
};