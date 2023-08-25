class Solution {
// private:
//     // Memoization
//     int countPaths(vector<vector<int>> &dp,int m,int n){
//         if(m==0 && n==0){
//             return 1;
//         }
//         if(m < 0 || n < 0){
//             return 0;
//         }
//         if(dp[m][n] != -1) return dp[m][n];
//         int up = countPaths(dp,m-1,n);
//         int left = countPaths(dp,m,n-1);
//         return dp[m][n] = up + left;
//     }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (m,vector<int>(n,-1));
        //Tabulation
        dp[0][0]=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
                int up = 0;
                int left = 0;
                if (i>0) up = dp[i-1][j];
                if (j>0) left = dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1];
    }
};