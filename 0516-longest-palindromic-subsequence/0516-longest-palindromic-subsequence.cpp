class Solution {
private:
    int solveTab(string & a, string & b){
        vector<vector<int>>DP(a.length()+1,vector<int>(b.length()+1,0));
        for(int i = a.length()-1;i>=0;i--){
            for(int j = b.length()-1;j>=0;j--){
                if(a[i]==b[j]) DP[i][j]= 1 + DP[i+1][j+1];
                else DP[i][j] = max(DP[i+1][j],DP[i][j+1]);
                
            }
        }
        return DP[0][0];        
    }    
public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        return solveTab(s,rev);
    }
};