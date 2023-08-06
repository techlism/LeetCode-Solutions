class Solution {
private:
    bool dfs(vector<vector<char>> & board, string word, int i, int j , int wordIndex){
        //visited all 
        if(wordIndex == word.size()) return true;
        // out of bound or not equal
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[wordIndex]) 
            return false;
        // Mark this visited for now
        board[i][j]='0';
        
        // go in all for direction if any one can find next char
        bool found = dfs(board,word,i+1,j,wordIndex+1) ||
                     dfs(board,word,i,j+1,wordIndex+1) ||
                     dfs(board,word,i-1,j,wordIndex+1) ||
                     dfs(board,word,i,j-1,wordIndex+1) ;
        
        // change marked to original character (backtracking)
        board[i][j]=word[wordIndex];
        
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return false;
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                // First find the first char then explore
                if(board[i][j]==word[0] && dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
        
    }
};