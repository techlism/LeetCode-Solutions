class Solution {
private:
    int countPaths(vector<vector<int>>& grid, vector<vector<vector<int>>>&dp,
                   int& k, int curr, int i, int j){
        if (j < 0 || i < 0) return 0;
        if (dp[i][j][curr] != -1) return dp[i][j][curr];
        if (i==0 && j==0){
            curr+=grid[0][0];
            return (int)(curr % k == 0);            
        }
        int up   = countPaths(grid,dp,k,(curr+grid[i][j])%k,i-1,j);
        int left = countPaths(grid,dp,k,(curr+grid[i][j])%k,i,j-1);
        dp[i][j][curr] = (left + up) % int(1e9+7);
        return dp[i][j][curr];
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (k, -1)));
        return countPaths(grid,dp,k,0,m-1,n-1);
    }
};