class Solution {
private:
    void dfs(string node,unordered_map<string,multiset<string>> &adjList,vector<string>& ans){
        while(!adjList[node].empty()){
            string next = * adjList[node].begin();
            adjList[node].erase(adjList[node].begin());
            dfs(next,adjList,ans);
        }
        ans.insert(ans.begin(),node);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>adjList;
        for(auto ticket : tickets) adjList[ticket[0]].insert(ticket[1]);
        vector<string> ans;
        dfs("JFK",adjList,ans);
        return ans;
    }
};