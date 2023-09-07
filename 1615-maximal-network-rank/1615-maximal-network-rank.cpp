class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> graph(n);
        for(auto road : roads){
            graph[road[0]].insert(road[1]);
            graph[road[1]].insert(road[0]);
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int links = graph[i].size() + graph[j].size();
                if(graph[i].find(j)!=graph[i].end() && graph[j].find(i) != graph[j].end()){
                    links-=1;
                }
                ans = max(ans,links);
            }
        }
        return ans;
    }
};