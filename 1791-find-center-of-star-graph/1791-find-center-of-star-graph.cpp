class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> degreeCount;
        int center = 0;
        int maxDegree = 0;

        for (const vector<int>& edge : edges) {
            degreeCount[edge[0]]++;
            degreeCount[edge[1]]++;

            if (degreeCount[edge[0]] > maxDegree) {
                maxDegree = degreeCount[edge[0]];
                center = edge[0];
            }

            if (degreeCount[edge[1]] > maxDegree) {
                maxDegree = degreeCount[edge[1]];
                center = edge[1];
            }
        }

        return center;
    }
};