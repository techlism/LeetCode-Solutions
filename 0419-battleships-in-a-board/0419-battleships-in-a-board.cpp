class Solution {
private:
    void dfs(vector<vector<char>> & board, int i, int j){
        if(i < 0 || i >= board.size() || j >= board[0].size() || j < 0 || board[i][j] !='X' )
            return;
        
        board[i][j]='*';
        dfs(board,i,j+1);
        dfs(board,i,j-1);
        dfs(board,i+1,j);
        dfs(board,i-1,j);
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
        for (int i = 0 ;i < board.size(); i++){
            for(int j=0;j < board[0].size(); j++){
                if(board[i][j]=='X'){
                    ans++;
                    dfs(board,i,j);
                }
            }
        }
        return ans;
    }
};