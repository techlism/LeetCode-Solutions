class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,list<int>>adjList;
        for(auto edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        int center = 0;
        int len = INT_MIN;
        for(auto itr : adjList) {
            int size = int(itr.second.size());
            if (size > len ){
                 len = size;
                center = itr.first;                
            }           
        }
        return center;
    }
};