class Solution {
private:
    int countPaths(vector<vector<int>>& obstacleGrid,
                   vector<vector<int>>&dp,int i, int j){    
        if(i==0 && j==0) return 1;
        if(i < 0 || j < 0 || obstacleGrid[i][j]==1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = countPaths(obstacleGrid,dp,i-1,j) 
                        + countPaths(obstacleGrid,dp,i,j-1); 
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]==1) return 0;
        vector<vector<int>> dp (obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return countPaths(obstacleGrid,dp,obstacleGrid.size()-1,obstacleGrid[0].size()-1);
    }
};