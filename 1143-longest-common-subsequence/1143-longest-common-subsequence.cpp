class Solution {
private:
    int solveRec(string & a, string & b,int i,int j){
        if(i >= a.length() || j >= b.length()) return 0;
        if(a[i]==b[j]) return 1 + solveRec(a,b,i+1,j+1);     
        else return max(solveRec(a,b,i+1,j),solveRec(a,b,i,j+1));
    }
    int solveMemo(string & a, string & b, int i, int j, vector<vector<int>> & DP){
        if(i >= a.length() || j >= b.length()) return 0;
        if(DP[i][j] != -1) return DP[i][j];
        if(a[i]==b[j]) return DP[i][j]= 1 + solveMemo(a,b,i+1,j+1,DP);
        else return DP[i][j] = max(solveMemo(a,b,i+1,j,DP),solveMemo(a,b,i,j+1,DP));
    }
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
    int longestCommonSubsequence(string text1, string text2) {
        // return solveRec(text1,text2,0,0);
        // vector<vector<int>>DP(text1.length(),vector<int>(text2.length(),-1));
        // return solveMemo(text1,text2,0,0,DP);
        return solveTab(text1,text2);
    }
};