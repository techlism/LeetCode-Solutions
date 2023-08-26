class Solution {
private:
    // memoization
    int minPath(vector<vector<int>> &grid, vector<vector<int>> &dp ,int i,int j){
        if( i==0 && j==0 ) return grid[0][0] ;
        if (i < 0 || j < 0 ) return 1e9;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(minPath(grid,dp,i-1,j),minPath(grid,dp,i,j-1));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp (m,vector<int>(n,-1));
        // return minPath(grid,dp,m-1,n-1);
        // Tabulation \U0001f447
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[i][j];
                    continue;
                }
                int up = grid[i][j];
                if(i>0) up+=dp[i-1][j];
                else up+=1e9;
                int left = grid[i][j];
                if(j>0) left+=dp[i][j-1];
                else left+=1e9;
                dp[i][j]=min(left,up);
            }
        }
        return dp[m-1][n-1];
    }
};