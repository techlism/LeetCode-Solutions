class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2) return points.size();
        int maxPoints = 2;
        
        for (int i = 0; i < points.size() - 1; i++) {
            auto p = points[i];
            unordered_map<double, int> slopeCount;
            int same = 1; // count the number of same points
            
            for (int j = i + 1; j < points.size(); j++) {
                auto q = points[j];
                
                if (p[0] == q[0] && p[1] == q[1]) {
                    same++;
                    continue;
                }
                
                double slope;
                if (p[0] == q[0]) {
                    slope = numeric_limits<double>::infinity(); // vertical line
                } else {
                    slope = static_cast<double>(q[1] - p[1]) / (q[0] - p[0]); // slope
                }
                
                slopeCount[slope]++;
            }
            
            int currMax = same; // maximum points on the same line
            
            for (const auto& entry : slopeCount) {
                currMax = max(currMax, entry.second + same);
            }
            
            maxPoints = max(maxPoints, currMax);
        }
        
        return maxPoints;
    }
};
// Basically we are using nested to and for a particular point find slope with rest other points and store it in a map then for the maximum value we can just find max from the values from the map.
// TC- O(N^2) and space complexity (O(n))