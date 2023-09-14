class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // TOPOLOGICAL SORT Using KAHN'S Algorithm
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for (auto prerequisite : prerequisites) {
            adj[prerequisite[0]].push_back(prerequisite[1]);
            indegree[prerequisite[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int nodesVisited = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            nodesVisited++;
            for (auto& neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return nodesVisited == numCourses;        
    }
};